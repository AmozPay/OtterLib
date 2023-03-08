/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** ShootMessageClient
*/

#ifndef SHOOTMESSAGECLIENT_HPP_
#define SHOOTMESSAGECLIENT_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"
#include "Deserializer.hpp"
#include "Serializer.hpp"
#include "OtterNetwork.hpp"
#include "SendMessageToServer.hpp"
#include "InputKeyEventSystem.hpp"

namespace Otter::Games::RType::System::GameClient::ShootMessageClient
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
    void ReceiveShootMessage(Otter::Core::Orchestrator& ref, std::string& data, int);

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void SendShootMessage(
        Otter::Core::Orchestrator& ref,
        std::size_t &playerIndex
    );
}

#endif /* !SHOOTMESSAGECLIENT_HPP_ */
