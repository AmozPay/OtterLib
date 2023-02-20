#include "OtterNetwork.hpp"

namespace Otter::Network {

    namespace Server {

        void init(Otter::Core::Orchestrator& ref)
        {
            std::cout << "initNetwork" << std::endl;
            auto& net = ref.get_components<Otter::Network::SocketComponent>();

            for (int i = 0; i < net.size(); i++) {
                if (net[i])
                    net[i]->channel = std::make_shared<Otter::Network::Socket>(8080);
            }
        }

        void update(Otter::Core::Orchestrator& ref)
        {
            auto& clients = ref.get_components<Otter::Network::ClientComponent>();
            auto& sock = ref.get_components<Otter::Network::SocketComponent>();

            for (int i = 0; sock.size(); i++) {
                if (sock[i])
                    auto& serv = *sock[i];
            }
            update_session(ref, serv);
        }

        void update_session(Otter::Core::Orchestrator& ref, Otter::Network::SocketComponent& soc)
        {
            auto size = get_index(soc);
            auto& serv = ref.get_components<Otter::Network::ServerComponent>()[size];
            std::vector<Otter::Network::Session*> connection = soc.getNewSession();

            std::stringstream data;
            for (auto& it : connection) {
                it->recv(data);
                std::uint32_t id = test_connect(serv, data);
                if (id != -1) {
                    ////////////// add a new clien
                    id = add_toServ(serv, it->get_endpoint());
                    add_client(ref, serv, id);
                    ///// send a validation msg
                    //////
                } else {
                    soc.disconnect(it->get_endpoint());
                }
            }
        }

        std::uint32_t add_toServ(Otter::Network::ServerComponent& serv, udp::endpoint const& endp)
        {
            auto id = selecId(serv);
            serv.netId.insert(id);
            serv.playerId[endp] = id;
            return id;
        }

        void add_client(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::uint32_t id)
        {
            Entity& e = ref.createEntity();
            ClientComponent tmp;

            tmp.seq = 0;
            tmp.id = id;
            ref.add_component(e, tmp);
        }

        std::uint32_t selecId(Otter::Network::ServerComponent& serv)
        {
            std::uint32_t old = 0;

             for (auto& it : serv.netId) {
                if (*it > old + 1) {
                    return old + 1;
                }
                old = *it;
            }
            return old + 1;
        }

        bool test_connect(Otter::Network::ServerCOmponent& serv, std::stringstream& dt)
        {
            if (!checMagic(dt))
                return -1;
            std::uint32_t seq = getUint(dt);
            std::uint32_t id = getUint(dt);
            if (id == 0 && seq == 0) {
                return id;
            } else if (id > 0 && seq > 0) {
                return id;
            } else
                return -1;
        }

    } // namespace Server
} // namespace Otter::Network
