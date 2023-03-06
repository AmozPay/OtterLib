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
        std::vector<std::uint32_t> mandatory_static;
        std::map<udp::endpoint, std::uint32_t> playerId;
        std::set<std::uint32_t> netId;
        std::vector<std::function<void(Otter::Core::Orchestrator&, std::string&, int)>> callBack;
    };
} // namespace Otter::Network

#endif /* SERVERCOMPONENT_H */
