#pragma once
#include <map>
#include <thread>
#include <mutex>
#include <memory>

#include <boost/asio.hpp>

#include "Session.hpp"

namespace Otter::Network {

    using boost::asio::ip::udp;

    class Socket {
        public:
            Socket(std::uint16_t port = 0);
            ~Socket(void);

            void send(const udp::endpoint& dest, const std::string& data);

            Otter::Network::Session *get_session(void) { return &(*_sessions.begin()).second; }

        protected:
        private:
            void _recv(void);

            boost::asio::io_context _io;
            udp::socket _socket;
            std::unordered_map<udp::endpoint, Session> _sessions;
            std::mutex _connections_lock;
            std::jthread _job{[this] { this->_io.run(); }};
    };
}