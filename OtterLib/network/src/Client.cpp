#include "Client.hpp"

#include "OtterNetwork.hpp"
#include "dtObj.hpp"

namespace Otter::Network::Client {
    ////////////////////////////////update for try to connect////////////////////////////////////

    int test_conect(Otter::Network::ServerComponent& serv, std::stringstream& dt)
    {
        if (!Otter::Network::Header::checMagic(dt))
            return -1;
        std::uint32_t seq = Otter::Network::Header::getUint(dt);
        std::uint32_t id = Otter::Network::Header::getUint(dt);
        std::uint8_t pac = Otter::Network::Header::getChar(dt);
        if (pac != 1)
            return -1;
        Otter::Network::dtObj dtobj = Otter::Network::Header::getDt(dt);
        if (dtobj.msgCode != Otter::Network::ACTIVATION)
            return -1;
        if (dtobj.ss != "ORDER 66")
            return -1;
        if (id == 0) {
            return -1;
        } else if (id > 0 && seq == 0)
            return id;
        return -1;
    }

    void update_session(Otter::Core::Orchestrator& ref, int index)
    {
        auto& soc = ref.get_components<Otter::Network::SocketComponent>()[index];
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[index];
        std::vector<Otter::Network::Session*> connection = soc->channel->get_new_sessions();

        if (connection.size() != 0) {
            std::stringstream data;
            connection[0]->recv(data);
            std::uint32_t id = test_conect(*serv, data);
            if (id != -1) {
                serv->netId.insert(id);
                serv->playerId[connection[0]->get_endpoint()] = id;
                ClientComponent tmp;
                tmp.seq = 0;
                tmp.id = id;
                ref.add_component(index, std::move(tmp));
            } else {
                soc->channel->disconnect(connection[0]->get_endpoint());
            }
        }
    }

    void update_connection(Otter::Core::Orchestrator& ref, int index)
    {
        auto& soc = ref.get_components<Otter::Network::SocketComponent>()[index];
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[index];
        const udp::endpoint servAddr = serv->playerId.begin()->first;
        std::stringstream ss;

        Otter::Network::Header::formatHeader(ss, 0, 0);
        Otter::Network::Serializer::saveArchive(ss, 0);
        soc->channel->send(servAddr, ss.str());
    }

    ///////////////////////////////send msg/////////////////////////////////
    int tramFillMandatory(std::stringstream& ss, Otter::Network::ClientComponent& cl)
    {
        size_t len = 0;
        int nb = 0;
        while (cl.mandatory_msg_list.size() != 0) {
            if (sizeof(cl.mandatory_msg_list.front()) + len > 10000)
                return nb;
            Otter::Network::Serializer::saveArchive(ss, cl.mandatory_msg_list.front());
            len = ss.str().size();
            cl.mandatory_msg_list.pop();
            nb++;
        }
        return nb;
    }

    int tramFill(std::stringstream& ss, Otter::Network::ClientComponent& cl)
    {
        size_t len = 0;
        int nb = 0;
        while (cl.msg_list.size() != 0) {
            if (sizeof(cl.msg_list.front()) + len > 10000)
                return nb;
            Otter::Network::Serializer::saveArchive(ss, cl.msg_list.front());
            len = ss.str().size();
            cl.msg_list.pop();
            nb++;
        }
        return nb;
    }

    bool tramSending(Otter::Network::Session& session, Otter::Network::ClientComponent& cl)
    {
        std::stringstream ss;
        std::stringstream tmp;
        bool ret = false;
        std::uint8_t nb = 0;

        Otter::Network::Header::formatHeader(ss, cl.seq, cl.id);
        if (cl.mandatory_msg_list.size() != 0 && ss.str().size() < 10000) {
            ret = true;
            nb += tramFillMandatory(tmp, cl);
        }
        if (cl.msg_list.size() != 0 && ss.str().size() < 10000)
            nb += tramFill(tmp, cl);
        Otter::Network::Serializer::saveArchive(ss, nb);
        ss << tmp.str();
        session.send(ss.str());
        return ret;
    }

    void update_msg(Otter::Core::Orchestrator& ref, int index)
    {
        auto& soc = ref.get_components<Otter::Network::SocketComponent>()[index];
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[index];
        auto& cl = ref.get_components<Otter::Network::ClientComponent>()[index];
        std::vector<Otter::Network::Session*> connection = soc->channel->get_sessions();

        if (connection.size() != 1)
            return;
        if (!cl || !soc || !serv)
            return;
        tramSending(*connection[0], *cl);
        cl->seq++;
    }

    ///////////////////////////recv update////////////////////////////////////////////
    void computeTram(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::stringstream& ss,
                     int index)
    {
        std::uint32_t magic = Otter::Network::Header::getUint(ss);
        std::uint32_t seq = Otter::Network::Header::getUint(ss);
        std::uint32_t id = Otter::Network::Header::getUint(ss);
        std::uint8_t pac = Otter::Network::Header::getChar(ss);
        Otter::Network::dtObj dt;

        if (pac == 0)
            return;
        for (int i = 0; pac > i; i++) {
            dt = Otter::Network::Header::getDt(ss);
            serv.callBack[dt.msgCode](ref, dt.ss, index);
        }
    }

    void update_recv(Otter::Core::Orchestrator& ref, int index)
    {
        auto& soc = ref.get_components<Otter::Network::SocketComponent>()[index];
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[index];
        auto& cl = ref.get_components<Otter::Network::ClientComponent>()[index];
        std::vector<Otter::Network::Session*> connection = soc->channel->get_sessions();

        if (connection.size() != 1)
            return;
        if (!soc || !serv || !cl)
            return;
        std::stringstream data;
        for (auto& it : connection) {
            it->recv(data);
            if (data.tellp() == data.tellg())
                continue;
            if (Otter::Network::Server::test_header(data, cl->id, cl->seq) == false)
                continue;
            computeTram(ref, *serv, data, index);
        }
    }

    ////////////////////////////////////////////////////////////////
    void init(Otter::Core::Orchestrator& ref)
    {
        std::cout << "initNetwork" << std::endl;
        auto& net = ref.get_components<Otter::Network::SocketComponent>();

        for (int i = 0; i < net.size(); i++) {
            if (net[i])
                net[i]->channel = std::make_shared<Otter::Network::Socket>(8082);
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
        /// if no connection try connect

        if (sock[index]->channel->get_sessions().size() != 1) {
            Otter::Network::Client::update_connection(ref, index);
            Otter::Network::Client::update_session(ref, index);
        } else {
            Otter::Network::Client::update_msg(ref, index);
            Otter::Network::Client::update_recv(ref, index);
        }
    }

    ///////////////////////////////////////////////
}; // namespace Otter::Network::Client
