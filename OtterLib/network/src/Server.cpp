#include "OtterNetwork.hpp"

namespace Otter::Network::Server {
        bool test_connect(Otter::Network::ServerComponent& serv, std::stringstream& dt)
        {
           if (!Otter::Network::Header::checMagic(dt))
                return -1;
            std::uint32_t seq = Otter::Network::Header::getUint(dt);
            std::uint32_t id = Otter::Network::Header::getUint(dt);
            if (id == 0 && seq == 0) {
                return id;
            } else if (id > 0 && seq > 0) {
                return id;
            } else
                return -1;
        }

        void add_client(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::uint32_t id)
        {
            Otter::Core::Entity e = ref.createEntity();
            ClientComponent tmp;

            tmp.seq = 0;
            tmp.id = id;
            ref.add_component(e, std::move(tmp));
        }

        std::uint32_t selecId(Otter::Network::ServerComponent& serv)
        {
            std::uint32_t old = 0;

            for (auto& it : serv.netId) {
                if (it > old + 1) {
                    return old + 1;
                }
                old = it;
            }
            return old + 1;
        }
        std::uint32_t add_toServ(Otter::Network::ServerComponent& serv, udp::endpoint const& endp)
        {
            auto id = selecId(serv);
            serv.netId.insert(id);
            serv.playerId[endp] = id;
            return id;
	}
        void init(Otter::Core::Orchestrator& ref)
        {
            std::cout << "initNetwork" << std::endl;
            auto& net = ref.get_components<Otter::Network::SocketComponent>();

            for (int i = 0; i < net.size(); i++) {
                if (net[i])
                    net[i]->channel = std::make_shared<Otter::Network::Socket>(8080);
            }
        }


        void update_session(Otter::Core::Orchestrator& ref, Otter::Network::SocketComponent& soc)
        {
	  auto size = ref.get_components<Otter::Network::SocketComponent>().get_index(soc);
            auto& serv = ref.get_components<Otter::Network::ServerComponent>()[size];
            std::vector<Otter::Network::Session*> connection = soc.channel->get_new_sessions();

            std::stringstream data;
            for (auto& it : connection) {
                it->recv(data);
                std::uint32_t id = test_connect(*serv, data);
                if (id != -1) {
                    ////////////// add a new clien
                    id = add_toServ(*serv, it->get_endpoint());
                    add_client(ref, *serv, id);
                    ///// send a validation msg
                    //////
                } else {
                    soc.channel->disconnect(it->get_endpoint());
                }
            }
        }

   void update(Otter::Core::Orchestrator& ref)
        {
            auto& clients = ref.get_components<Otter::Network::ClientComponent>();
            auto& sock = ref.get_components<Otter::Network::SocketComponent>();
            int index = -1;
       
            for (int i = 0; sock.size(); i++) {
                if (sock[i])
                    index = i;
            }
	    if (index == -1)
	      return;
            update_session(ref, *sock[index]);
        }



} // namespace Otter::Network
