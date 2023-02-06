#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind/bind.hpp>
#include <array>
#include <memory>
#include <queue>
#include <thread>
#include <iostream>

namespace Otter::Network{

  class NetChannel {
    public:
      NetChannel(void) : _io(), _socket(_io, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8080)), _stream() {
    this->start_recv();

    _job = std::jthread([this]() {_io.run(); std::cout << "endllop" << std::endl;});                                                                              
    std::cout << "construct" << std::endl;
  }
        ~NetChannel() {};
      void send(boost::asio::ip::udp::endpoint& dest, std::stringstream& data);
     void recv(std::stringstream& data);
     void start_recv(void);

    void handle_recv(const boost::system::error_code& err, std::size_t rcvd, std::shared_ptr<std::string> data);
      void handle_send(const boost::system::error_code& err, std::size_t sent, std::shared_ptr<std::string> data);

      protected:
      private:
        boost::asio::io_context _io;
        boost::asio::ip::udp::socket _socket;
        std::jthread _job;
        boost::asio::ip::udp::endpoint _remote;

        std::stringstream _stream;
    };
} // namespace Otter::Network::NetChannel
