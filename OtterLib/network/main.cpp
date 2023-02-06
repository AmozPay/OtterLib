#include "NetChannel.hpp"

#include <iostream>

int main()
{
  Otter::Network::NetChannel tmp;
  std::cout << "out" << std::endl;
  std::stringstream dt;
    std::stringstream ress;
    boost::asio::io_context io;
    boost::asio::ip::udp::resolver res(io);
    
    boost::asio::ip::udp::endpoint tests(*res.resolve(boost::asio::ip::udp::v4(), "localhost", "8080").begin());

    
    dt << "try to work";
  
    while (1) {


      std::cout << "loop" << std::endl;
      tmp.send(tests, dt);
      std::cout << "sending  " << dt.str() << std::endl;
      sleep(3);
      tmp.recv(ress);

      std::cout <<"reciev dt  " << ress.str() << std::endl;
  } 
}
