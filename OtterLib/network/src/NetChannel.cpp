#include "NetChannel.hpp"

#include <iostream>

namespace Otter::Network {
  /*
  NetChannel::NetChannel(void) : _io(), _socket(_io, udp::endpoint(udp::v4(), 8080)), _stream(), _buff() {
    this->start_recv();
    _buff = std::make_shared<std::string>('\0', 1024);

    
    //std::jthread _job = std::jthread([this]() {std::cout << "ICE" << std::endl; _io.run(); std::cout << "endllop" << std::endl;});

    std::cout << "construct" << std::endl;
    }*/


  void NetChannel::start_recv(void)
  {
   std::shared_ptr<std::string> _buff = std::make_shared<std::string>("\0", 1024);

    _socket.async_receive_from(	
			       boost::asio::buffer(*(_buff)), _remote,
  std::bind(&NetChannel::handle_recv, this, std::placeholders::_1, std::placeholders::_2, _buff));
  }


  void NetChannel::handle_recv(const boost::system::error_code& err, std::size_t rcvd, std::shared_ptr<std::string> data)
{
      std::cout << "recieving dt:" << rcvd<< std::endl;
      if (!err) {
	std::cout << "reci no error " << std::endl;
      } else {
            std::cerr << err << std::endl;
        }
      //  start_recv();
    }

  void NetChannel::recv(std::stringstream& data) { data << "recieve"; }

  void NetChannel::handle_send(const boost::system::error_code& err, std::size_t rcvd, std::shared_ptr<std::string> data)
{
      std::cout << data << std::endl;
        if (!err) {
         std::cout << "sending dt:" << rcvd << std::endl;

        } else {
            std::cerr << err << std::endl;
        }
    }

  void NetChannel::send(boost::asio::ip::udp::endpoint& dest, std::stringstream& data)
    {
        std::shared_ptr<std::string> buff = std::make_shared<std::string>(data.str());

        _socket.async_send_to( boost::asio::buffer(buff->data(), buff->length()), dest,
			       std::bind(&NetChannel::handle_send, this, std::placeholders::_1, std::placeholders::_2, buff));
    }

} // namespace Otter::Network::NetChannel
