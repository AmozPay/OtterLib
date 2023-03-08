/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameOverSystem
*/

#ifndef GAMEOVERSYSTEMCLIENT_HPP_
#define GAMEOVERSYSTEMCLIENT_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::GameClient::GameOver {
    namespace utils = Otter::Games::RType::Utils;
    namespace components = Otter::Games::RType::Components;

    void TriggerGameOver(Otter::Core::Orchestrator& ref);

    void CheckGameOver(Otter::Core::Orchestrator& ref);

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void HandleGameOver(Otter::Core::Orchestrator& ref, std::vector<std::size_t>&);
} // namespace Otter::Games::RType::System::GameOver

#endif /* !GAMEOVERSYSTEM_HPP_ */
