/*
** EPITECH PROJECT, 2023
** bootstrap_rtype [WSL: Ubuntu]
** File description:
** UdpClient
*/

#ifndef UDPCLIENT_HPP_
#define UDPCLIENT_HPP_

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

using udp = boost::asio::ip::udp;

class UdpClient {
    public:
        UdpClient(boost::asio::io_context &context);
        UdpClient(
            const std::string &ip,
            const std::string &port,
            boost::asio::io_context &context);
        ~UdpClient();
        void init(const std::string &ip, const std::string &port);
        void sendData(std::stringbuf& buf);
        void receiveData();

    private:
        void _handleSend(
            boost::array<char, 128> recv_buffer /*message*/,
            const boost::system::error_code& /*error*/,
            std::size_t /*bytes_transferred*/);
        boost::asio::io_context &_context;
        udp::socket _socket;
        udp::endpoint _targetEndpoint;
        boost::array<char, 128> _recv_buffer;

};

#endif /* !UDPCLIENT_HPP_ */
