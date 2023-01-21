/*
** EPITECH PROJECT, 2023
** bootstrap_rtype [WSL: Ubuntu]
** File description:
** UdpClient
*/

#ifndef UDPCLIENT_HPP_
#define UDPCLIENT_HPP_

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>

using udp = boost::asio::ip::udp;

class UdpClient {
  public:
    UdpClient(boost::asio::io_context &context);
    UdpClient(const std::string &ip, const std::string &port, boost::asio::io_context &context);
    ~UdpClient();
    void init(const std::string &ip, const std::string &port);
    void sendData(char *line);
    void receiveData();

  private:
    boost::asio::io_context &_context;
    udp::socket _socket;
    udp::endpoint _targetEndpoint;
};

#endif /* !UDPCLIENT_HPP_ */
