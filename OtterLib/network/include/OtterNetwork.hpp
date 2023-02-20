
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

      private:
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
            } else if (id > 0 && seq > 0)
                return id;
        }

        else return -1;
    }

};

/*******************************************************************/
struct ServerComponent {
    std::vector<int> mandatory_static;
    std::map<udp::endpoint, std::uint32_t> playerId;
    std::set<std::uint32_t> netId;
}

struct ClientComponent {
    ClientComponent() : msg_list(), mandatory_msg_list(), mandatory_buffer() {}

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

/////////////////// header
class header {
  public:
    extern std::uint32_t magicFunc();

    std::optional<std::uint32_t> checMagic(std::stringstream& ss);
    std::uint32_t getUint(std::stringstream& ss);
    std::uint8_t getChar(std::stringstream& ss);
    dtObj getDt(std::stringstream& ss);

    void formatHeader(std::stringstream& ss, std::uint32_t seq, std::uint32_t id);
};

// user developer interface for sending data through the server or cleint //
class Sender {
  public:
    void broadCast_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::stringstream& dt);
    void send_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::uint32_t id, std::stringstream& dt);
    dtObj&& convertDtObj(MsgCode msg, std::stringstream& dt);
    std::stringstream convertDtObj(dtObj const& obj);

    bool isMandatory(Otter::Core::Orchestrator& ref, MsgCode msg);
    void queueDtObj(Otter::Core::Orchestrator& ref, Otter::Network::ClientComponent& cl, dtObj&& obj);
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
