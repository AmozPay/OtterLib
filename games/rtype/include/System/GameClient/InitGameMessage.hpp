/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitGameMessage
*/

#ifndef INITGAMEMESSAGE_HPP_
#define INITGAMEMESSAGE_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::GameClient::InitGameMessage {

    namespace utils = Otter::Games::RType::Utils;
    namespace components = Otter::Games::RType::Components;

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void HandleInitGameMessage(Otter::Core::Orchestrator& ref, std::string&, int);
} // namespace Otter::Games::RType::System::GameClient::InitGameMessage

#endif /* !INITGAMEMESSAGE_HPP_ */
