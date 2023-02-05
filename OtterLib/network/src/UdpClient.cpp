/*
** EPITECH PROJECT, 2023
** bootstrap_rtype [WSL: Ubuntu]
** File description:
** UdpClient
*/

#include "UdpClient.hpp"

UdpClient::UdpClient(boost::asio::io_context &context)
: _context(context), _socket(context)
{
    
}

UdpClient::UdpClient(
    const std::string &ip,
    const std::string &port,
    boost::asio::io_context &context)
: _context(context), _socket(context)
{
    udp::resolver resolver(context); 

    _targetEndpoint = *resolver.resolve(udp::v4(), ip, port).begin();
    _socket.open(udp::v4());
}

UdpClient::~UdpClient()
{

}

void UdpClient::init(const std::string &ip, const std::string &port)
{
    udp::resolver resolver(_context);

    _targetEndpoint = *resolver.resolve(udp::v4(), ip, port).begin();
    _socket.open(udp::v4());
}

void UdpClient::_handleSend(boost::shared_ptr<std::string> /*message*/,
    const boost::system::error_code& /*error*/,
    std::size_t /*bytes_transferred*/)
{

}

void UdpClient::sendData(std::stringbuf& buf)
{
    std::cout << std::string(buf.str()) << std::endl;
    _socket.send_to(boost::asio::buffer(buf.str(), buf.str().length()), _targetEndpoint);
}


void UdpClient::receiveData()
{    
    _socket.async_send_to(
        _recv_buffer,
        _targetEndpoint,
        boost::bind(&UdpClient::_handleSend, this, rec,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}
