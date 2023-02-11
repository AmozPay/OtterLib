// #pragma once

// #include "asio.hpp"

// #include <array>
// #include <memory>
// #include <queue>
// #include <thread>

// namespace Otter::Network::NetChannel {

//     typedef asio::ip::udp udp;

//     class NetChannel {
//       public:
//         NetChannel(void);
//         void send(udp::endpoint& dest, std::stringstream& data);
//         void recv(std::stringstream& data);

//       protected:
//       private:
//         void start_recv(void);
//         void handle_recv(const asio::error_code& err, std::size_t rcvd, std::shared_ptr<std::string> data);
//         void handle_send(const asio::error_code& err, std::size_t sent, std::shared_ptr<std::string> data);

//         asio::io_context _io;
//         udp::socket _socket{_io, udp::endpoint(udp::v4(), 6969)};
//         std::jthread _job{[this] { _io.run(); }};
//         udp::endpoint _remote;
//         std::stringstream _stream;
//     };
// } // namespace Otter::Network::NetChannel