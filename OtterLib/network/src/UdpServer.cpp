/*
** EPITECH PROJECT, 2023
** server [WSL: Ubuntu]
** File description:
** UdpServer
*/

#include "UdpServer.hpp"

UdpServer::UdpServer(boost::asio::io_context& io_context)
: _socket(io_context, udp::endpoint(udp::v4(), 8080))
{
    _startReceive();
}

UdpServer::~UdpServer()
{

}

void UdpServer::_startReceive()
{
    _socket.async_receive_from(
        _recv_buffer,
        _remote_endpoint,
        boost::bind(&UdpServer::_handleReceive, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void UdpServer::_handleReceive(
    const boost::system::error_code& error,
    std::size_t test)
{

    if (!error) {
        _startReceive();
    }
}

void UdpServer::_handleSend(boost::shared_ptr<std::string> /*message*/,
    const boost::system::error_code& /*error*/,
    std::size_t /*bytes_transferred*/)
{

}

void UdpServer::sendData(std::stringbuf& buf) {
    _socket.async_send_to(
        boost::asio::buffer(buf.str()),
        _remote_endpoint,
        boost::bind(&UdpServer::_handleSend, this, buf.str(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}