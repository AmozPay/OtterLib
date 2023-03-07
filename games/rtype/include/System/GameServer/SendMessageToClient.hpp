/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** SendMessageToClient
*/

#ifndef SENDMESSAGETOCLIENT_HPP_
#define SENDMESSAGETOCLIENT_HPP_

#include "OtterNetwork.hpp"
#include "NetworkComponent.hpp"

namespace Otter::Games::RType::System::GameServer::SendMessageToClient
{
    namespace network = Otter::Network;

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void Send(Otter::Core::Orchestrator& ref, network::MsgCode msg, std::stringstream& data);
}

#endif /* !SENDMESSAGETOCLIENT_HPP_ */
