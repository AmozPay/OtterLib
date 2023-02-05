/*
** EPITECH PROJECT, 2023
** server [WSL: Ubuntu]
** File description:
** UdpServer
*/

#ifndef UDPSERVER_HPP_
#define UDPSERVER_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using udp = boost::asio::ip::udp;

class UdpServer {
    public:
        UdpServer(boost::asio::io_context &context);
        ~UdpServer();

    private:
        udp::socket _socket;
        udp::endpoint _remote_endpoint;
        boost::array<char, 128> _recv_buffer;

        void _startReceive();
        void _handleReceive(const boost::system::error_code& error, std::size_t);
        void _handleSend(
            boost::shared_ptr<std::string> /*message*/,
            const boost::system::error_code& /*error*/,
            std::size_t /*bytes_transferred*/);
        void UdpServer::sendData(std::stringbuf& buf);

};

#endif /* !UDPSERVER_HPP_ */
