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
        NetworkComponent(int port, int portToSend): channel(port)
        { 
            this->port = port;
            this->portToSend = portToSend;
        };
        int port;
        int portToSend;
        NetChannel::NetChannel channel;
    };
}

#endif /* !NETWORKCOMPONENT_HPP_ */
