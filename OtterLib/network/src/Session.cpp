#include "Session.hpp"

#include "Socket.hpp"

#include <boost/thread/with_lock_guard.hpp>
#include <iostream>

Otter::Network::Session::Session(const udp::endpoint& endpoint, Socket& socket)
    : _socket(socket), _endpoint(endpoint), _data_lock(std::make_shared<std::mutex>())
{
    std::cout << "New connection from " << _endpoint << std::endl;
}

void Otter::Network::Session::recv(std::stringstream& data)
{
    boost::with_lock_guard(*this->_data_lock,
                           [this, &data]
                           {
                               data.write(_data.str().c_str(), 22);
                               _data.str("");
                           });
}

void Otter::Network::Session::send(const std::string& data) { _socket.send(this->_endpoint, data); }

const Otter::Network::udp::endpoint& Otter::Network::Session::get_endpoint(void) const { return _endpoint; }