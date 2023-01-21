/*
** EPITECH PROJECT, 2023
** bootstrap_rtype [WSL: Ubuntu]
** File description:
** UdpClient
*/

#include "UdpClient.hpp"

UdpClient::UdpClient(boost::asio::io_context &context) : _context(context), _socket(context) {}

UdpClient::UdpClient(const std::string &ip, const std::string &port,
                     boost::asio::io_context &context)
    : _context(context), _socket(context) {
    udp::resolver resolver(context);

    _targetEndpoint = *resolver.resolve(udp::v4(), ip, port).begin();
    _socket.open(udp::v4());
}

UdpClient::~UdpClient() {}

void UdpClient::init(const std::string &ip, const std::string &port) {
    udp::resolver resolver(_context);

    _targetEndpoint = *resolver.resolve(udp::v4(), ip, port).begin();
    _socket.open(udp::v4());
}

void UdpClient::sendData(char *line) {
    std::cout << std::string(line) << std::endl;
    _socket.send_to(boost::asio::buffer(line, std::strlen(line)), _targetEndpoint);
}

void UdpClient::receiveData() {
    boost::array<char, 128> recv_buf;
    udp::endpoint sender_endpoint;

    size_t len = _socket.receive_from(boost::asio::buffer(recv_buf), _targetEndpoint);

    std::cout.write(recv_buf.data(), len);
}
