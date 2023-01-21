/*
** EPITECH PROJECT, 2023
** server [WSL: Ubuntu]
** File description:
** UdpServer
*/

#include "UdpServer.hpp"

UdpServer::UdpServer(boost::asio::io_context &io_context)
    : _socket(io_context, udp::endpoint(udp::v4(), 8080)) {
    _startReceive();
}

UdpServer::~UdpServer() {}

void UdpServer::_startReceive() {
    _socket.async_receive_from(boost::asio::buffer(_recv_buffer, 65), _remote_endpoint,
                               boost::bind(&UdpServer::_handleReceive, this,
                                           boost::asio::placeholders::error,
                                           boost::asio::placeholders::bytes_transferred));
}

void UdpServer::_handleReceive(const boost::system::error_code &error, std::size_t test) {

    if (!error) {
        boost::shared_ptr<std::string> message(new std::string(makeDaytimeString()));

        std::cout << test << std::endl;
        std::cout << _recv_buffer << std::endl;
        std::cout << *message << std::endl;

        _socket.async_send_to(boost::asio::buffer(*message), _remote_endpoint,
                              boost::bind(&UdpServer::_handleSend, this, message,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred));

        _startReceive();
    }
}

void UdpServer::_handleSend(boost::shared_ptr<std::string> /*message*/,
                            const boost::system::error_code & /*error*/,
                            std::size_t /*bytes_transferred*/) {}

std::string UdpServer::makeDaytimeString() {
    using namespace std; // For time_t, time and ctime;
    time_t now = time(0);
    return ctime(&now);
}