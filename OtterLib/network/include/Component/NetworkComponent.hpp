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
    struct SocketComponent {
        SocketComponent() : channel(nullptr){};

        std::shared_ptr<Otter::Network::Socket> channel;
    };
} // namespace Otter::Network

#endif /* !NETWORKCOMPONENT_HPP_ */
