/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** SendMessageToServer
*/

#include "SendMessageToServer.hpp"

namespace Otter::Games::RType::System::GameClient::SendMessageToServer
{
    namespace network = Otter::Network;

    void Send(
        Otter::Core::Orchestrator& ref,
        network::MsgCode msg,
        std::stringstream& data
    ) {
        auto& servers = ref.get_components<Otter::Network::ServerComponent>();

        for (std::size_t i = 0; i < servers.size(); i++) {
            auto &server = servers[i]; 

            if (!server)
                continue;

            for (auto &[enpoint, clientId]: server->playerId) {
                network::Sender::send_msg(ref, msg, clientId, data);
            }
        }
    }
}