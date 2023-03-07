/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** MovePlayerMessage
*/

#ifndef MOVEPLAYERMESSAGECLIENT_HPP_
#define MOVEPLAYERMESSAGECLIENT_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"
#include "Deserializer.hpp"
#include "Serializer.hpp"
#include "OtterNetwork.hpp"
#include "SendMessageToServer.hpp"

namespace Otter::Games::RType::System::GameClient::MovePlayerMessage
{
    namespace utils = Otter::Games::RType::Utils;
    namespace components = Otter::Games::RType::Components;
    namespace baseComponent = Otter::Core::BaseComponents;
    namespace network = Otter::Network;
    namespace system = Otter::Games::RType::System;

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void ReceiveMovePlayerMessage(Otter::Core::Orchestrator& ref, std::string& data, int);

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void SendMovePlayerMessage(
        Otter::Core::Orchestrator& ref,
        std::size_t &playerIndex,
        utils::EventState &state
    );
}

#endif /* !MOVEPLAYERMESSAGECLIENT_HPP_ */
