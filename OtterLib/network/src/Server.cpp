#include "Server.hpp"
#include "bitset"
#include "OtterNetwork.hpp"

namespace Otter::Network::Server {

    ///////////////////////////////Tools//////////////////////////////////////////

    ////////////////////////////new connection update///////////////////////////
    int test_conect(Otter::Network::ServerComponent& serv, std::stringstream& dt)
    {
        if (!Otter::Network::Header::checMagic(dt))
            return -1;
        std::uint32_t seq = Otter::Network::Header::getUint(dt);
        std::uint32_t id = Otter::Network::Header::getUint(dt);
        std::uint8_t pac = Otter::Network::Header::getChar(dt);
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

        tmp.seq = 1;
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

    std::string connectMsg(std::uint32_t id)
    {
        std::stringstream ss;
        std::uint8_t nb = 0;

        Otter::Network::Header::formatHeader(ss, 0, id);
        Otter::Network::Serializer::saveArchive<std::uint8_t>(ss, 1);
        Otter::Network::dtObj obj;
        obj.msgCode = Otter::Network::ACTIVATION;
        obj.ss = "ORDER 66";
        Otter::Network::Serializer::saveArchive(ss, obj);
        std::cout << "Order 66" << std::endl;
        return ss.str();
    }

    void update_session(Otter::Core::Orchestrator& ref, Otter::Network::SocketComponent& soc)
    {
        auto size = ref.get_components<Otter::Network::SocketComponent>().get_index(soc);
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[size];
        std::vector<Otter::Network::Session*> connection = soc.channel->get_new_sessions();

        std::stringstream data;
        for (auto& it : connection) {
            it->recv(data);
            std::cout << "new connection arrive " << data.str() << "|" << std::endl;
            std::uint32_t id = Otter::Network::Server::test_conect(*serv, data);
            if (id != -1) {
                ////////////// add a new clien
                id = add_toServ(*serv, it->get_endpoint());
                add_client(ref, *serv, id);
                it->send(connectMsg(id));
                ///// send a validation msg
            } else {
                std::cout << "socket disconnect" << std::endl;
                soc.channel->disconnect(it->get_endpoint());
            }
        }
    }

    /////////////////////////////////////send update///////////////////////////////////////////
    // here will be added a verification prosses
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
        cl.mandatory_buffer.push(std::pair(nb, ss.str()));
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

        if (cl.mandatory_buffer.size() == 0) {
            Otter::Network::Header::formatHeader(ss, cl.seq, cl.id);
            if (cl.mandatory_msg_list.size() != 0 && ss.str().size() < 10000) {
                ret = true;
                nb += tramFillMandatory(tmp, cl);
            }
        } else {
            Otter::Network::Header::formatHeader(ss, cl.mandatory_seq, cl.id);
            ss << cl.mandatory_buffer.front().second;
            nb = cl.mandatory_buffer.front().first;
            ret = true;
        }

        if (cl.msg_list.size() != 0 && ss.str().size() + tmp.str().size() < 10000)
            nb += tramFill(tmp, cl);

        if (ret == true)
            nb = nb | 0X80;

        Otter::Network::Serializer::saveArchive(ss, nb);
        ss << tmp.str();
        if (ss.str().size() == 0 || nb == 0)
            return ret;
        std::cout << "Tram Sending" << std::endl;
        session.send(ss.str());
        std::cout << "msg send" << ss.str() << std::endl;
        return ret;
    }

    void update_msg(Otter::Core::Orchestrator& ref, int index)
    {
        auto& soc = ref.get_components<Otter::Network::SocketComponent>()[index];
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[index];
        auto& cl = ref.get_components<Otter::Network::ClientComponent>();
        std::vector<Otter::Network::Session*> connection = soc->channel->get_sessions();
        int j = 0;

        for (int i = 0; cl.size() > i; i++) {
            if (!cl[i])
                continue;
            for (j = 0; connection.size() > j; j++) {
                if (serv->playerId[connection[j]->get_endpoint()] == cl[i]->id)
                    break;
            }
            if (tramSending(*connection[j], *cl[i])) {
	      std::cout << "mandatory bind" << cl[i]->seq << std::endl;
	      cl[i]->mandatory_seq = cl[i]->seq;
            } else {
                cl[i]->seq++;
            }
        }
    }

    ////////////////////////////recieve update///////////////////////////////////
    bool test_header(std::stringstream const& dt, int idRef, int seqR)
    {
        std::stringstream ss(dt.str());

        if (!Otter::Network::Header::checMagic(ss))
            return false;
        std::uint32_t seq = Otter::Network::Header::getUint(ss);
        std::uint32_t id = Otter::Network::Header::getUint(ss);
        std::uint8_t pac = Otter::Network::Header::getChar(ss);
        if (id == 0 && seq == 0)
            return false;
        if (id != idRef)
            return false;

        /*	if ((pac & 0X80) >> 7) // cas ou le bit 8 de pac est egale a true
              if (seq > seqR_mandatory) { // si le mandatory a jamais ete traité
              return true;
            }

        } else {
         if (seq <= seqR)
           return false;
        }*/
        return true;
    }

    void validation_handcheck(Otter::Core::Orchestrator& ref, std::uint32_t cl_index, std::string& tmp)
    {
        auto& cl = ref.get_components<Otter::Network::ClientComponent>()[cl_index];
        std::stringstream ss(tmp);
        std::uint32_t seq = Otter::Network::Header::getUint(ss);

        if (seq == cl->mandatory_seq) {
            cl->mandatory_buffer.pop();
            cl->seq++;
        }
	std::cout << "handcheck" << std::endl;
    }

    void validation_msg(Otter::Core::Orchestrator& ref, int index, int seqManda)
    {
        auto& soc = ref.get_components<Otter::Network::SocketComponent>()[0];
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[0];
        auto& cl = ref.get_components<Otter::Network::ClientComponent>();
        std::vector<Otter::Network::Session*> connection = soc->channel->get_sessions();
        int j = 0;

        std::stringstream ss;
        std::stringstream tmp;
        std::uint8_t nb = 0;

        Otter::Network::Header::formatHeader(ss, cl[index]->seq, cl[index]->id);
        Otter::Network::Serializer::saveArchive<std::uint8_t>(ss, 1);
        Otter::Network::dtObj obj;
        obj.msgCode = Otter::Network::VALIDATION;
        Otter::Network::Serializer::saveArchive<std::uint32_t>(tmp, seqManda);
        obj.ss = tmp.str();
        Otter::Network::Serializer::saveArchive(ss, obj);

        for (j = 0; connection.size() > j; j++) {
            if (serv->playerId[connection[j]->get_endpoint()] == cl[index]->id)
                break;
        }
        connection[j]->send(ss.str());
        std::cout << "validation " << ss.str() << std::endl;
    }

    bool compute_manda(Otter::Core::Orchestrator& ref, int index, std::uint32_t seqRecv, bool manda)
    {
        auto& cl = ref.get_components<Otter::Network::ClientComponent>();

        if (manda == true) {
	  std::cout << "passing in mandatory" << seqRecv << cl[index]->mandatory_recv_seq <<std::endl;
            validation_msg(ref, index, seqRecv);
            if (cl[index]->mandatory_recv_seq == seqRecv) {
	      std::cout << "already recieve" << std::endl;
                return true;
            } else {
	        std::cout << "recieve new" << std::endl;
            }
            cl[index]->mandatory_recv_seq = seqRecv;
        }
        return false;
    }

    int computeTram(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::stringstream& ss,
                    int index)
    {
        std::uint32_t magic = Otter::Network::Header::getUint(ss);
        std::uint32_t seq = Otter::Network::Header::getUint(ss);
        std::uint32_t id = Otter::Network::Header::getUint(ss);
        std::uint8_t pac = Otter::Network::Header::getChar(ss);
        dtObj dt;
        int manda = (pac & 0X80) >> 7; 
	if (manda)
           pac = pac ^ 0X80;

        if (pac == 0)
            return 0;
        for (int i = 0; pac > i; i++) {
            dt = Otter::Network::Header::getDt(ss);
            if (dt.msgCode == Otter::Network::ACTIVATION) {
                return -1;
            }
            if (compute_manda(ref, index, seq, manda) == true)
                continue;
            if (dt.msgCode == Otter::Network::VALIDATION) {
                validation_handcheck(ref, index, dt.ss);
                continue;
            }
            serv.callBack[dt.msgCode](ref, dt.ss, index);
        }
        return 0;
    }

    void update_recv(Otter::Core::Orchestrator& ref, int index)
    {
        auto& soc = ref.get_components<Otter::Network::SocketComponent>()[index];
        auto& serv = ref.get_components<Otter::Network::ServerComponent>()[index];
        auto& cl = ref.get_components<Otter::Network::ClientComponent>();
        std::vector<Otter::Network::Session*> connection = soc->channel->get_sessions();
        int j = -1;
        std::stringstream data;

        for (auto& it : connection) {
	    for (j = -1; cl.size() > j + 1; j++) {
                if (serv->playerId[it->get_endpoint()] == cl[j + 1]->id) {
                    j = j + 1;
                    break;
                }
            }
            if (j == -1 || cl.size() == j) {
	      continue;
	    }
            it->recv(data);
            if (data.str().empty())
                continue;
	    while (!data.str().empty()) {
	    if (test_header(data, cl[j]->id, cl[j]->seq) == false)
                continue;
            if (computeTram(ref, *serv, data, j) == -1) {
                std::cout << "doublon" << std::endl;
                soc->channel->disconnect(it->get_endpoint());
            }
	    }
        }
    }

    //////////////////////////general update//////////////////////////////////
    void update(Otter::Core::Orchestrator& ref)
    {
        auto& clients = ref.get_components<Otter::Network::ClientComponent>();
        auto& sock = ref.get_components<Otter::Network::SocketComponent>();
        int index = -1;

        for (int i = 0; i < sock.size(); i++) {
            if (sock[i])
                index = i;
        }
        if (index == -1)
            return;
        // std::cout << "gooing to update with index:" << index << std::endl;
        update_session(ref, *sock[index]);
        //	std::cout << "entering msg" << std::endl;
        update_msg(ref, index);
        update_recv(ref, index);
        // std::cout << "end update" << std::endl;
    }

    void init(Otter::Core::Orchestrator& ref)
    {
        std::cout << "initNetwork  server" << std::endl;
        auto& net = ref.get_components<Otter::Network::SocketComponent>();

        for (int i = 0; i < net.size(); i++) {
            if (net[i])
                net[i]->channel = std::make_shared<Otter::Network::Socket>(net[i]->ip, net[i]->port);
        }
    }

} // namespace Otter::Network::Server
