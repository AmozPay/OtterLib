#ifndef CLIENTCOMPONENT_H
#define CLIENTCOMPONENT_H

#include "Socket.hpp"
#include "dtObj.hpp"

#include <queue>
#include <utility>
#include <vector>

namespace Otter::Network {
    struct ClientComponent {
        ClientComponent() : msg_list(), mandatory_msg_list(), mandatory_buffer() {}

        std::uint32_t seq;
        std::uint32_t id;
        std::queue<dtObj> msg_list;
        std::queue<dtObj> mandatory_msg_list;
        std::vector<dtObj> mandatory_buffer;
    };
} // namespace Otter::Network

#endif /* CLIENTCOMPONENT_H */
