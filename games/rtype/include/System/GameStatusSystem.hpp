/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameStatusSystem
*/

#ifndef GAMESTATUSSYSTEM_HPP_
#define GAMESTATUSSYSTEM_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::GameStatus {

    namespace utils = Otter::Games::RType::Utils;
    namespace components = Otter::Games::RType::Components;

    /**
     * @brief Handle the game status event
     * @details This function is used to handle the game status
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void HandleGameStatus(Otter::Core::Orchestrator& ref);
} // namespace Otter::Games::RType::System::GameStatus

#endif /* !GAMESTATUSSYSTEM_HPP_ */
