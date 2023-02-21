
#ifndef OTTERNETWORK_H
#define OTTERNETWORK_H

#include "Deserializer.hpp"
#include "NetworkComponent.hpp"
#include "Networkable.hpp"
#include "Serializer.hpp"
#include "Socket.hpp"

#include <iostream>
#include <queue>
#include <set>
#include <utility>

namespace Otter::Network {

    enum MsgCode {
        VAR,
    };

    /**********************************************/

    struct dtObj : public Otter::Network::Serializable {

        dtObj(){};
        ~dtObj(){};

        boost::archive::binary_oarchive& operator&(boost::archive::binary_oarchive& archive)
        {
            archive& msgCode;
            archive& ss;
            return archive;
        }

        boost::archive::binary_iarchive& operator&(boost::archive::binary_iarchive& archive)
        {
            archive& msgCode;
            archive& ss;
            return archive;
        }

        std::uint32_t msgCode;
        std::string ss;
    };

    /*******************************************************************/
    struct ServerComponent {
        std::vector<int> mandatory_static;
        std::map<udp::endpoint, std::uint32_t> playerId;
        std::set<std::uint32_t> netId;
    };

    struct ClientComponent {
        ClientComponent() : msg_list(), mandatory_msg_list(), mandatory_buffer() {}

        std::uint32_t seq;
        std::uint32_t id;
        std::queue<dtObj> msg_list;
        std::queue<dtObj> mandatory_msg_list;
        std::vector<dtObj> mandatory_buffer;
    };

    /***********************************************************/
    class Server {
      public:
        void init(Otter::Core::Orchestrator& ref);
        void update(Otter::Core::Orchestrator& ref);
        void update_session(Otter::Core::Orchestrator& ref, Otter::Network::SocketComponent& soc);

      private:
        std::uint32_t add_toServ(Otter::Network::ServerComponent& serv, udp::endpoint const& endp);
        void add_client(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::uint32_t id);
        std::uint32_t selecId(Otter::Network::ServerComponent& serv);
        bool test_connect(Otter::Network::ServerComponent& serv, std::stringstream& dt);
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

    /////////////////// header
    namespace Header {
        static std::uint32_t magicFunc();

        std::optional<std::uint32_t> checMagic(std::stringstream& ss);
        std::uint32_t getUint(std::stringstream& ss);
        std::uint8_t getChar(std::stringstream& ss);
        dtObj getDt(std::stringstream& ss);

        void formatHeader(std::stringstream& ss, std::uint32_t seq, std::uint32_t id);
    }; // namespace Header

    // user developer interface for sending data through the server or cleint //
    namespace Sender {
        bool isMandatory(Otter::Core::Orchestrator& ref, std::uint32_t msg);
        void broadCast_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::stringstream& dt);
        void send_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::uint32_t id, std::stringstream& dt);
        dtObj&& convertDtObj(MsgCode msg, std::stringstream& dt);
        std::stringstream convertDtObj(dtObj const& obj);

        void queueDtObj(Otter::Core::Orchestrator& ref, Otter::Network::ClientComponent& cl, dtObj&& obj);
    }; // namespace Sender

} // namespace Otter::Network
#endif /* OTTERNETWORK_H */

/*

server =  header + dtObj * X

dtObj = msgcode + msgdt


 */
