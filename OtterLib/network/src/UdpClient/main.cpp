/*
** EPITECH PROJECT, 2023
** client [WSL: Ubuntu]
** File description:
** main
*/

#include "UdpClient.hpp"

int main(int argc, char *argv[]) {
    std::string ip;
    std::string port;
    boost::asio::io_context context;
    UdpClient client(context);

    if (argc != 3) {
        std::cerr << "Usage: client <host> <ip>" << std::endl;
        return 1;
    }

    ip = argv[1];
    port = argv[2];

    try {
        client.init(ip, port);

        char line[64 + 1];
        while (std::cin.getline(line, 64 + 1)) {
            client.sendData(line);
            client.receiveData();
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}