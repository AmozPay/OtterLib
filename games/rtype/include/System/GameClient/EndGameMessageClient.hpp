/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** EndGameMessageClient
*/

#ifndef ENDGAMEMESSAGECLIENT_HPP_
#define ENDGAMEMESSAGECLIENT_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"
#include "Deserializer.hpp"
#include "Serializer.hpp"
#include "OtterNetwork.hpp"
#include "SendMessageToServer.hpp"

namespace Otter::Games::RType::System::GameClient::EndGameMessage
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
    void ReceiveGameOver(Otter::Core::Orchestrator& ref, std::string&, int);

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void SendGameOver(Otter::Core::Orchestrator& ref);

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void ReceiveWin(Otter::Core::Orchestrator& ref, std::string&, int);

    /**
     * @brief Handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void SendWin(Otter::Core::Orchestrator& ref);
}

#endif /* !ENDGAMEMESSAGECLIENT_HPP_ */
