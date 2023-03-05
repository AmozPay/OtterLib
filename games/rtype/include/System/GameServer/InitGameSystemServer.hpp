/*
** EPITECH PROJECT, 2023
** $
** File description:
** InitGameSystem
*/

#ifndef INITGAMESYSTEMSERVER_HPP_
#define INITGAMESYSTEMSERVER_HPP_

#include "OtterCore.hpp"
#include "baseComponents.hpp"
#include "EventComponent.hpp"
#include "Utils.hpp"

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
}

#endif /* !INITGAMESYSTEMSERVER_HPP_ */
