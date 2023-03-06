/*
** EPITECH PROJECT, 2023
** $
** File description:
** InitGameSystem
*/

#ifndef INITGAMESYSTEMSERVER_HPP_
#define INITGAMESYSTEMSERVER_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::GameServer::InitGame {

    namespace utils = Otter::Games::RType::Utils;
    namespace components = Otter::Games::RType::Components;

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void HandleInitGame(Otter::Core::Orchestrator& ref, std::vector<std::size_t>&);
} // namespace Otter::Games::RType::System::InitGame

#endif /* !INITGAMESYSTEMSERVER_HPP_ */
