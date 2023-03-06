/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** NetworkComponent
*/

#ifndef NETWORKCOMPONENT_HPP_
#define NETWORKCOMPONENT_HPP_

#include "Socket.hpp"
#include "Factory.hpp"
#include <boost/asio.hpp>

namespace Otter::Network {
    struct SocketComponent {
      COMPONENT_BUILDER(Socket)                                                                                  
       {                                                                                                          
          auto port = json.get<std::uint16_t>("port");                                                             
          auto ip = json.get<std::string>("ip");
          
          SocketComponent net;
          net.ip = ip;
          net.port = port;
          core.add_component(e , std::move(net));
       }

      SocketComponent() : channel(nullptr){};
      
      std::shared_ptr<Otter::Network::Socket> channel;
      std::uint16_t port;
      std::string ip;
    };
} // namespace Otter::Network

#endif /* !NETWORKCOMPONENT_HPP_ */
