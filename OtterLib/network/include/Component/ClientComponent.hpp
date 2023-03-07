#ifndef CLIENTCOMPONENT_H
#define CLIENTCOMPONENT_H

#include "Socket.hpp"
#include "dtObj.hpp"

#include <queue>
#include <utility>
#include <vector>

namespace Otter::Network {
    struct ClientComponent {
      ClientComponent() : msg_list(), mandatory_msg_list(), mandatory_buffer() {seq = 1; mandatory_seq = 1; mandatory_recv_seq = 0;}

        std::uint32_t seq; // seq actuee
        std::uint32_t id;
        std::queue<dtObj> msg_list;
        std::queue<dtObj> mandatory_msg_list;
        std::queue<std::pair<int, std::string>> mandatory_buffer; // nb pack and dt
        std::uint32_t mandatory_seq;                              // seq of the last send
        std::uint32_t mandatory_recv_seq;                         // seq of the last recieve
    };
} // namespace Otter::Network

#endif /* CLIENTCOMPONENT_H */
