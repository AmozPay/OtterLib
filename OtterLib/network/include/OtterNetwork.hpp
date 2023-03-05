
#ifndef OTTERNETWORK_H
#define OTTERNETWORK_H

#include "Client.hpp"
#include "ClientComponent.hpp"
#include "Deserializer.hpp"
#include "NetworkComponent.hpp"
#include "Networkable.hpp"
#include "Orchestrator.hpp"
#include "Serializer.hpp"
#include "Server.hpp"
#include "ServerComponent.hpp"
#include "Socket.hpp"

#include <iostream>
#include <queue>
#include <set>
#include <utility>

namespace Otter::Network {

    enum MsgCode {
        ACTIVATION,
        VAR,
    };

    /////////////////// header
    namespace Header {
        static std::uint32_t magicFunc();
        bool checMagic(std::stringstream& ss);
        std::uint32_t getUint(std::stringstream& ss);
        std::uint8_t getChar(std::stringstream& ss);
        dtObj getDt(std::stringstream& ss);

        void formatHeader(std::stringstream& ss, std::uint32_t seq, std::uint32_t id);
    }; // namespace Header

    // user developer interface for sending data through the server or cleint //
    namespace Sender {
        bool isMandatory(Otter::Core::Orchestrator& ref, std::uint32_t msg);
        void broadCast_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::stringstream& dt);
        void send_msg(Otter::Core::Orchestrator& ref, MsgCode msg, std::uint32_t client_id, std::stringstream& dt);
        dtObj convertDtObj(MsgCode msg, std::stringstream& dt);

        void queueDtObj(Otter::Core::Orchestrator& ref, Otter::Network::ClientComponent& cl, dtObj&& obj);
    }; // namespace Sender

} // namespace Otter::Network
#endif /* OTTERNETWORK_H */
