#pragma once
#include "Session.hpp"
#include "Factory.hpp"
#include <boost/asio.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <thread>

namespace Otter::Network {

    using boost::asio::ip::udp;

    class Socket {
      public:
        COMPONENT_BUILDER(Socket)
        {
          auto port = json.get<std::uint16_t>("port");
          auto ip = json.get<std::string>("ip");
          core.add_component(Otter::Network::Socket(ip, port));
        }
        Socket(std::uint16_t port = 0);
        Socket(boost::asio::ip::address addr, std::uint16_t port = 0);
        Socket(std::string add, std::uint16_t port = 0);
        ~Socket(void);

        /**
         * @brief Function for sendind a string data
         * @details the data send is copy in a temporary smart pointer, the function is a non Blocking one
         *
         * @params a udp endpoint of the target
         * @params a const reference of string to the data to send
         *
         */
        void send(const udp::endpoint& dest, const std::string& data);

        /**
         * @brief Disconnects the session identified by dest.
         * @details As the protocol is UDP based, "disconnecting" only means "removing from sessions list"
         *
         * @param dest The endpoint of the session to close.
         * @return `true` if a session was closed `false` otherwise.
         */
        bool disconnect(const udp::endpoint& dest);

        std::vector<Otter::Network::Session*> get_sessions(void);

        std::vector<Otter::Network::Session*> get_new_sessions(void);

      protected:
      private:
        void _recv(void);

        boost::asio::io_context _io;
        udp::socket _socket;
        std::unordered_map<udp::endpoint, Session> _sessions;
        std::mutex _sessions_lock;
        std::vector<udp::endpoint> _new_sessions;
        std::mutex _new_sessions_lock;
        std::jthread _job{[this]
                          {
                              this->_io.run();
                              std::cout << "ioend" << std::endl;
                          }};
    };
} // namespace Otter::Network
