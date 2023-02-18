
#include "Socket.hpp"

#include <boost/thread/with_lock_guard.hpp>
#include <iostream>

Otter::Network::Socket::Socket(std::uint16_t port) : _socket(_io, udp::endpoint(udp::v4(), port))
{
    std::cout << "Socket bound to " << _socket.local_endpoint() << std::endl;
    this->_recv();
}

Otter::Network::Socket::Socket(boost::asio::ip::address addr, std::uint16_t port)
    : _socket(_io, udp::endpoint(addr, port))
{
    std::cout << "Socket bound to " << _socket.local_endpoint() << std::endl;
    this->_recv();
}

Otter::Network::Socket::Socket(std::string addr, std::uint16_t port)
    : _socket(_io, udp::endpoint(boost::asio::ip::address::from_string(addr), port))

{
    std::cout << "Socket bound to " << _socket.local_endpoint() << std::endl;
    this->_recv();
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
                          { std::cout << "Sent " << sent << " byte(s) to " << dest << std::endl; });
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
                        _connections_lock,
                        [this, source] {
                            return this->_sessions.insert({*source, Session(*source, *this)}).first;
                        });
                }
                std::cout << "Received " << rcvd << " byte(s) from " << *source << std::endl;
                boost::with_lock_guard(*con->second._data_lock,
                                       [con, data, rcvd] { con->second._data.write((*data).data(), rcvd); });
            }
            this->_recv();
        });
    std::cout << "_recv registered" << std::endl;
}
