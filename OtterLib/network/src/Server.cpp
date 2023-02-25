#include "OtterNetwork.hpp"

namespace Otter::Network::Server {

  ////////////////////////////new connection update///////////////////////////
    int test_conect(Otter::Network::ServerComponent& serv, std::stringstream& dt)
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
        std::cout << "initNetwork  server" << std::endl;
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
  
  /////////////////////////////////////send update///////////////////////////////////////////
    // here will be added a verification prosses
    void tramFillMandatory(std::stringstream& ss, Otter::Network::ClientComponent& cl)
    {
        size_t len = 0;

        while (cl.mandatory_msg_list.size() != 0) {
            if (sizeof(cl.mandatory_msg_list.front()) + len > 10000)
                return;
            Otter::Network::Serializer::saveArchive(ss, cl.mandatory_msg_list.front());
            len = ss.str().size();
            cl.mandatory_msg_list.pop();
        }
    }

    void tramFill(std::stringstream& ss, Otter::Network::ClientComponent& cl)
    {
        size_t len = 0;

        while (cl.msg_list.size() != 0) {
            if (sizeof(cl.msg_list.front()) + len > 10000)
                return;
            Otter::Network::Serializer::saveArchive(ss, cl.msg_list.front());
            len = ss.str().size();
            cl.msg_list.pop();
        }
    }

    bool tramSending(Otter::Network::Session& session, Otter::Network::ClientComponent& cl)
    {
        std::stringstream ss;
        bool ret = false;

        Otter::Network::Header::formatHeader(ss, cl.seq, cl.id);
        if (cl.mandatory_msg_list.size() != 0 && ss.str().size() < 10000) {
            ret = true;
            tramFillMandatory();
        }
        if (cl.msg_list.size() != 0 && ss.str().size() < 10000)
            tramFill();
        session.send(ss.str());
        return ret;
    }

    void update_msg(Otter::Core::Orchestrator& ref, int index)
    {
        auto& soc = ref.get_components<Otter::Network::SocketComponent>()[index];
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[index];
        auto& cl = ref.get_components<Otter::Network::ClientComponent>();
        std::vector<Otter::Network::Session*> connection = soc.channel->get_sessions();
        int i = 0;

        for (int i = 0; cl.size() > i; i++) {
            if (!cl[i])
                continue;
            for (i = 0; connection.size() > i; i++) {
                if (serv.playerId[connection[i]->get_endpoint()] == cl.id)
                    break;
            }
            tramSending(connection[i], *cl[i]);
	    cl.seq ++;
        }
    }
  //////////////////////////general update//////////////////////////////////
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
        update_msg(reg, index);
    }

} // namespace Otter::Network::Server
