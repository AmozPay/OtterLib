/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** NetworkComponent
*/

#ifndef NETWORKCOMPONENT_HPP_
#define NETWORKCOMPONENT_HPP_

#include "NetChannel.hpp"

#include <boost/asio.hpp>

namespace Otter::Network {
    struct NetworkComponent {
        NetworkComponent(int port, int portToSend) : channel(nullptr)
        {
            this->port = port;
            this->portToSend = portToSend;
        };

        void init() { channel = std::make_shared<Otter::Network::NetChannel>(port); }

        int port;
        int portToSend;
        std::shared_ptr<Otter::Network::NetChannel> channel;
    };
} // namespace Otter::Network

#endif /* !NETWORKCOMPONENT_HPP_ */
