/*
** EPITECH PROJECT, 2023
** r-type_server [WSL: Ubuntu]
** File description:
** main
*/

#include "UdpServer.hpp"

int main() {
    try {
        boost::asio::io_context io_context;
        UdpServer server(io_context);

        io_context.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}