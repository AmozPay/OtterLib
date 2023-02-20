
#ifndef OTTERNETWORK_H
#define OTTERNETWORK_H

#include "Deserializer.hpp"
#include "NetworkComponent.hpp"
#include "Networkable.hpp"
#include "Serializer.hpp"
#include "Socket.hpp"

namespace Otter::Network {

    class Server {
      public:
        void broadCast_msg(Otter::Core::Orchestrator& ref, int msg) {}

        void send_msg(Otter::Core::Orchestrator& ref, unint32_t id) {}

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
                if (test_connect(serv, data))
                    // init /connect
                    else
                    {
                        soc.disconnect(it->get_endpoint());
                    }
            }
        }

      private:
        bool test_connect(Otter::Network::ServerCOmponent& serv, std::stringstream& dt) {}
    };

    /*******************************************************************/
    struct ServerComponent {
        std::vector<int> mandatory_static;
        std::vector<udp::endpoint> playerId;

    }

    struct ClientComponent {

        std::uint32_t seq;
        std::uint32_t id;
        std::queue<dtObj> msg_list;
        std::queue<dtObj> mandatory_msg_list;
        std::vector<dtObj> mandatory_buffer;
    };

    /***********************************************************/

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

    // user developer interface for sending data through the server or cleint //
    class Sender {
        void broadCast_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::stringstream& dt);
        void send_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::uint32_t id, std::stringstream& dt);

        bool isMandatory(Otter::Core::Orchestrator& ref, MsgCode msg);
        void queueDtObj(Otter::Core::Orchestrator& ref, Otter::Network::ClientComponent& cl, dtObj&& obj);
        dtObj&& convertDtObj(MsgCode msg, std::stringstream& dt);
        std::stringstream convertDtObj(dtObj const& obj);
    };

    struct dtObj : public Otter::Network::Serializable {

        dtObj(){};
        ~dtObj(){};

        boost::archive::binary_oarchive& operator&(boost::archive::binary_oarchive& archive)
        {
            archive& len;
            archive& ss;
            return archive;
        }

        boost::archive::binary_iarchive& operator&(boost::archive::binary_iarchive& archive)
        {
            archive& len;
            archive& ss;
            return archive;
        }

        std::uint32_t msgCode;
        std::string ss;
    };

} // namespace Otter::Network
#endif /* OTTERNETWORK_H */

/*

server =  header + dtObj * X

dtObj = msgcode + msgdt


 */
