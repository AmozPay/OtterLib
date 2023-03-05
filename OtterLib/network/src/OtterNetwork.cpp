#include "OtterNetwork.hpp"

/*************************** sender ***********/
namespace Otter::Network::Sender {
    void broadCast_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::stringstream& dt)
    {
        auto& clients = ref.get_components<Otter::Network::ClientComponent>();

        for (int i = 0; i < clients.size(); i++) {
            if (!clients[i])
                continue;
            dtObj obj;
            obj.msgCode = msg;
            obj.ss = dt.str();
            if (isMandatory(ref, msg)) {
                clients[i]->mandatory_msg_list.push(obj);
            } else {
                clients[i]->msg_list.push(obj);
            }
        }
    }

    bool isMandatory(Otter::Core::Orchestrator& ref, std::uint32_t msg)
    {
        auto& serv = ref.get_components<Otter::Network::ServerComponent>();
        std::optional<Otter::Network::ServerComponent> comp;

        for (int i = 0; i < serv.size(); i++)
            if (serv[i]) {
                comp = serv[i];
                break;
            }

        for (int i = 0; comp->mandatory_static.size() > i; i++) {
            if (comp->mandatory_static[i] == msg)
                return true;
        }
        return false;
    }

    void send_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::uint32_t client_id, std::stringstream& dt)
    {
        auto& clients = ref.get_components<Otter::Network::ClientComponent>();

        for (int i = 0; i < clients.size(); i++) {
            if (!clients[i])
                continue;
            if (clients[i]->id == client_id) {
                queueDtObj(ref, *(clients[i]), convertDtObj(msg, dt));
                break;
            }
            if (i + 1 == clients.size())
                return;
        }
    }

    void queueDtObj(Otter::Core::Orchestrator& ref, Otter::Network::ClientComponent& cl, dtObj&& obj)
    {
        if (isMandatory(ref, obj.msgCode)) {
            cl.mandatory_msg_list.push(obj);
        } else {
            cl.msg_list.push(obj);
        }
    }

    dtObj convertDtObj(MsgCode msg, std::stringstream& dt)
    {
        dtObj obj;

        obj.msgCode = msg;
        obj.ss = dt.str();
        return obj;
    }

} // namespace Otter::Network::Sender

std::uint32_t Otter::Network::Header::magicFunc() { return 42; };

namespace Otter::Network::Header {

    bool checMagic(std::stringstream& ss)
    {
        std::uint32_t tmp = Otter::Network::Deserializer::loadArchive<std::uint32_t>(ss);
        if (Header::magicFunc() == tmp)
            return true;
        return false;
    }

    std::uint32_t getUint(std::stringstream& ss)
    {
        return Otter::Network::Deserializer::loadArchive<std::uint32_t>(ss);
    }

    std::uint8_t getChar(std::stringstream& ss) { return Otter::Network::Deserializer::loadArchive<std::uint8_t>(ss); }

    dtObj getDt(std::stringstream& ss) { return Otter::Network::Deserializer::loadArchive<dtObj>(ss); }

    void formatHeader(std::stringstream& ss, std::uint32_t seq, std::uint32_t id)
    {
        Otter::Network::Serializer::saveArchive<std::uint32_t>(ss, Header::magicFunc());
        Otter::Network::Serializer::saveArchive(ss, seq);
        Otter::Network::Serializer::saveArchive(ss, id);
    }

    //    ytmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);
    // ztmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);

} // namespace Otter::Network::Header
