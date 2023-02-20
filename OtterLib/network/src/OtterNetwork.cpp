#include "OtterNetwork.hpp"

/*************************** sender ***********/ / namespace Sender
{
    void broadCast_msg(Otter::Core::Orchestrator & ref, MsgCode msg, std::stringstream & dt)
    {
        auto& clients = ref.get_components<Otter::Network::ClientComponent>();

        for (int i = 0; i < clients.size(); i++) {
            if (!clients)
                continue;
            dtObj obj;
            obj.msgCode = msg;
            obj.ss = dt.str();
            if (isMandatory(ref, msg)) {
                clients->mandatory_msg_list.push(obj);
            } else {
                clients->msg_list.push(obj);
            }
        }
    }

    bool isMandatory(Otter::Core::Orchestrator & ref, MsgCode msg)
    {
        auto& ser = ref.get_components<Otter::Network::ServerComponent>();
        std::optional<Otter::Network::ServerComponent> comp;

        for (int i = 0; i < ser.size(); i++)
            if (serv[i]) {
                comp = ser[i];
                break;
            }

        for (auto& it : comp.mandatory_static.size()) {
            if (*it == msg)
                return true;
        }
        return false;
    }

    void send_msg(Otter::Core::Orchestrator & ref, MsgCode msg, std::uint32_t id, std::stringstream & dt)
    {
        auto& clients = ref.get_components<Otter::Network::ClientComponent>();
        Otter::Network::ClientComponent& comp;

        for (int i = 0; i < clients.size(); i++) {
            if (!clients)
                continue;
            if (clients[i].id == id) {
                comp = clients[i];
                break;
            }
            if (i + 1 == clients.size())
                return;
        }

        queueDtObj(ref, comp, convertDtObj(msg, dt));
    }

    void queueDtObj(Otter::Core::Orchestrator & ref, Otter::Network::ClientComponent & cl, dtObj && obj)
    {
        if (isMandatory(ref, obj.msgCode)) {
            clients->mandatory_msg_list.push(obj);
        } else {
            clients->msg_list.push(obj);
        }
    }

    dtObj&& convertDtObj(MsgCode msg, std::stringstream & dt)
    {
        dtObj obj;

        obj.msgCode = msg;
        obj.ss = dt.str();
        return std::move(obj);
    }

    std::stringstream convertDtObj(dtObj const& obj) { return std::stringstream(obj.ss); }
}
