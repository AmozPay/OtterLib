#ifndef OTTERNETWORK_H
#define OTTERNETWORK_H

#include "Deserializer.hpp"
#include "NetworkComponent.hpp"
#include "Networkable.hpp"
#include "Serializer.hpp"
#include "Socket.hpp"

namespace Otter::Network {

    class Server {
        void init(Otter::Core::Orchestrator& ref)
        {
            std::cout << "initNetwork" << std::endl;
            auto& net = ref.get_components<Otter::Network::SocketComponent>();

            for (int i = 0; i < net.size(); i++) {
                if (net[i])
                    net[i]->channel = std::make_shared<Otter::Network::Socket>(8080);
            }
        }
    };

    class Client {
        void init(Otter::Core::Orchestrator& ref)
        {
            std::cout << "initNetwork" << std::endl;
            auto& net = ref.get_components<Otter::Network::SocketComponent>();

            for (int i = 0; i < net.size(); i++) {
                if (net[i])
                    net[i]->channel = std::make_shared<Otter::Network::Socket>(8081);
            }
        }
    };

} // namespace Otter::Network
#endif /* OTTERNETWORK_H */
