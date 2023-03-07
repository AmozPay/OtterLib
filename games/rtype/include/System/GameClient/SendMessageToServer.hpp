/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** SendMessageToServer
*/

#ifndef SENDMESSAGETOSERVER_HPP_
#define SENDMESSAGETOSERVER_HPP_

#include "OtterNetwork.hpp"
#include "NetworkComponent.hpp"

namespace Otter::Games::RType::System::GameClient::SendMessageToServer
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

#endif /* !SENDMESSAGETOSERVER_HPP_ */
