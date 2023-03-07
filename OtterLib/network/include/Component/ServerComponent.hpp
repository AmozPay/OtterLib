#ifndef SERVERCOMPONENT_H
#define SERVERCOMPONENT_H
#include "Orchestrator.hpp"
#include "Socket.hpp"
#include "dtObj.hpp"

#include <functional>
#include <map>
#include <set>
#include <utility>
#include <vector>

namespace Otter::Network {

    // Do insert no push back -> 0 need to be reserved
    struct ServerComponent {
        COMPONENT_BUILDER(RemoteServer)
        {
            auto port = json.get_optional<std::uint16_t>("RemotePort");
            auto ip = json.get_optional<std::string>("RemoteIp");

            if (!port && !ip) {
                core.add_component(e, ServerComponent());
                return;
            }
            ServerComponent net;
            if (!port) {
                net.playerId[udp::endpoint(boost::asio::ip::address::from_string(*ip), 8080)] = 0;
                return;
            }
            if (!ip) {
                net.playerId[udp::endpoint(udp::v4(), *port)] = 0;
                core.add_component(e, std::move(net));
                return;
            }

            net.playerId[udp::endpoint(boost::asio::ip::address::from_string(*ip), *port)] = 0;
            core.add_component(e, std::move(net));
        }

        std::vector<std::uint32_t> mandatory_static;
        std::map<udp::endpoint, std::uint32_t> playerId;
        std::set<std::uint32_t> netId;
        std::vector<std::function<void(Otter::Core::Orchestrator&, std::string&, int)>> callBack;
    };
} // namespace Otter::Network

#endif /* SERVERCOMPONENT_H */
