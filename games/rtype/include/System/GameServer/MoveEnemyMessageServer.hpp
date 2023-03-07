/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** MovePlayerMessage
*/

#ifndef MOVEENEMYMESSAGESERVER_HPP_
#define MOVEENEMYMESSAGESERVER_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"
#include "Deserializer.hpp"
#include "Serializer.hpp"
#include "OtterNetwork.hpp"
#include "OtterNetwork.hpp"

namespace Otter::Games::RType::System::GameServer::MoveEnemyMessage
{
    namespace utils = Otter::Games::RType::Utils;
    namespace components = Otter::Games::RType::Components;
    namespace baseComponent = Otter::Core::BaseComponents;
    namespace network = Otter::Network;
    namespace system = Otter::Games::RType::System;


    void SendMoveEnemyMessage(
        Otter::Core::Orchestrator& ref,
        int &enemyId,
        utils::Vector2 &pos
    );
}

#endif /* !MOVEPLAYERMESSAGE_HPP_ */
