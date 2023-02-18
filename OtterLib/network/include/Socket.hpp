#pragma once
#include "Session.hpp"

#include <boost/asio.hpp>
#include <map>
#include <memory>
#include <mutex>
#include <thread>

namespace Otter::Network {

    using boost::asio::ip::udp;

    class Socket {
      public:
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

        std::vector<Otter::Network::Session*> get_sessions(void)
        {
            std::vector<Otter::Network::Session*> tmp;

            for (auto& it : _sessions) {
                tmp.insert(tmp.end(), &(it.second));
            }
            return tmp;
        }

      protected:
      private:
        void _recv(void);

        boost::asio::io_context _io;
        udp::socket _socket;
        std::unordered_map<udp::endpoint, Session> _sessions;
        std::mutex _connections_lock;
        std::jthread _job{[this] { this->_io.run(); }};
    };
} // namespace Otter::Network
