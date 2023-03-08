
#include "Socket.hpp"

#include <boost/thread/with_lock_guard.hpp>
#include <iostream>

Otter::Network::Socket::Socket(std::uint16_t port) : _socket(_io, udp::endpoint(udp::v4(), port))
{
    this->_recv();
    this->_job = std::jthread{[this]
                              {
                                  this->_io.run();
                                  std::cout << "Io end" << std::endl;
                              }};
    std::cout << "Socket bound to " << _socket.local_endpoint() << std::endl;
}

Otter::Network::Socket::Socket(boost::asio::ip::address addr, std::uint16_t port)
    : _socket(_io, udp::endpoint(addr, port))
{
    this->_recv();
    this->_job = std::jthread{[this]
                              {
                                  this->_io.run();
                                  std::cout << "Io end" << std::endl;
                              }};
    std::cout << "Socket bound to " << _socket.local_endpoint() << std::endl;
}

Otter::Network::Socket::Socket(std::string addr, std::uint16_t port)
    : _socket(_io, udp::endpoint(boost::asio::ip::address::from_string(addr), port))

{
    this->_recv();
    this->_job = std::jthread{[this]
                              {
                                  this->_io.run();
                                  std::cout << "Io end" << std::endl;
                              }};
    std::cout << "Socket bound to " << _socket.local_endpoint() << std::endl;
}

Otter::Network::Socket::~Socket(void)
{
    _io.stop();
    _socket.close();
}

void Otter::Network::Socket::send(const udp::endpoint& dest, const std::string& data)
{
    std::shared_ptr<std::string> save = std::make_shared<std::string>(data);

    _socket.async_send_to(boost::asio::buffer(*save), dest,
                          [this, dest, save](const boost::system::error_code& err, std::size_t sent)
                          { /* std::cout << "Sent " << sent << " byte(s) to " << dest << std::endl;*/ });
}

void Otter::Network::Socket::_recv(void)
{
    std::shared_ptr<std::array<char, 1024>> data = std::make_shared<std::array<char, 1024>>();
    std::shared_ptr<udp::endpoint> source = std::make_shared<udp::endpoint>();

    _socket.async_receive_from(
        boost::asio::buffer(*data, 1024), *source,
        [this, source, data](const boost::system::error_code& err, std::size_t rcvd)
        {
            if (err) {
                std::cerr << err << std::endl;
            } else {
                auto con = this->_sessions.find(*source);
                if (con == this->_sessions.end()) {
                    con = boost::with_lock_guard(
                        _sessions_lock,
                        [this, source]
                        {
                            std::scoped_lock lock(this->_new_sessions_lock);
                            this->_new_sessions.push_back(*source);
                            return this->_sessions.insert({*source, Session(*source, *this)}).first;
                        });
                }
                // std::cout << "Received " << rcvd << " byte(s) from " << *source << std::endl;
                boost::with_lock_guard(*con->second._data_lock,
                                       [con, data, rcvd] { con->second._data.write((*data).data(), rcvd); });
            }
            this->_recv();
        });
    //std::cout << "_recv registered" << std::endl;
}

bool Otter::Network::Socket::disconnect(const udp::endpoint& dest)
{
    std::scoped_lock lock(_sessions_lock, _new_sessions_lock);
    auto session = this->_sessions.find(dest);

    if (session == this->_sessions.end())
        return false;
    this->_sessions.erase(dest);
    auto ep = std::find(_new_sessions.begin(), _new_sessions.end(), dest);
    if (ep != _new_sessions.end())
        _new_sessions.erase(ep);
    return true;
}

std::vector<Otter::Network::Session*> Otter::Network::Socket::get_sessions(void)
{
    std::vector<Otter::Network::Session*> tmp;
    std::scoped_lock lock(_sessions_lock, _new_sessions_lock);

    for (auto& it : _sessions) {
        if (std::find(_new_sessions.begin(), _new_sessions.end(), it.second._endpoint) == _new_sessions.end()) {
            tmp.insert(tmp.end(), &(it.second));
        }
    }
    return tmp;
}

std::vector<Otter::Network::Session*> Otter::Network::Socket::get_new_sessions(void)
{
    std::vector<Otter::Network::Session*> tmp;
    std::scoped_lock lock(_sessions_lock, _new_sessions_lock);

    for (auto& it : _sessions) {
        auto ep = std::find(_new_sessions.begin(), _new_sessions.end(), it.second._endpoint);
        if (ep != _new_sessions.end()) {
            tmp.insert(tmp.end(), &(it.second));
            _new_sessions.erase(ep);
        }
    }
    return tmp;
}
