/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** MovePlayerMessage
*/

#ifndef MOVEPLAYERMESSAGESERVER_HPP_
#define MOVEPLAYERMESSAGESERVER_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"
#include "Deserializer.hpp"
#include "Serializer.hpp"
#include "OtterNetwork.hpp"
#include "OtterNetwork.hpp"

namespace Otter::Games::RType::System::GameServer::MovePlayerMessage
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

    void SendMovePlayerMessage(
        Otter::Core::Orchestrator& ref,
        int &playerId,
        utils::Vector2 &pos
    );
}

#endif /* !MOVEPLAYERMESSAGE_HPP_ */
