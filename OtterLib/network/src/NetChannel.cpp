// #include "NetChannel.hpp"

// #include <iostream>

// namespace Otter::Network::NetChannel {

//     NetChannel::NetChannel(void) {}

//     void NetChannel::start_recv(void)
//     {
//         std::shared_ptr<std::string> buf = std::make_shared<std::string>('\0', 1024);

//         _socket.async_receive_from(
//             asio::buffer(*buf), _remote,
//             std::bind(&NetChannel::handle_recv, this, std::placeholders::_1, std::placeholders::_2, buf));
//     }

//     void NetChannel::handle_recv(const asio::error_code& err, std::size_t rcvd, std::shared_ptr<std::string> data)
//     {
//         if (!err) {
//             _stream << data;
//         } else {
//             std::cerr << err << std::endl;
//         }
//         start_recv();
//     }

//     void NetChannel::recv(std::stringstream& data) { data << _stream.str(); }

//     void NetChannel::handle_send(const asio::error_code& err, std::size_t rcvd, std::shared_ptr<std::string> data)
//     {
//         if (!err) {

//         } else {
//             std::cerr << err << std::endl;
//         }
//     }

//     void NetChannel::send(udp::endpoint& dest, std::stringstream& data)
//     {
//         std::shared_ptr<std::string> buf = std::make_shared<std::string>(data.str());
//         _socket.async_send_to(
//             asio::buffer(buf->data(), buf->length()), dest,
//             std::bind(&NetChannel::handle_send, this, std::placeholders::_1, std::placeholders::_2, buf));
//     }

// } // namespace Otter::Network::NetChannel
