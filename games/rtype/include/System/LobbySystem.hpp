/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** LobbySystem
*/

#ifndef LOBBYSYSTEM_HPP_
#define LOBBYSYSTEM_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"
#include "System.hpp"

namespace Otter::Games::RType::System::Lobby {

    namespace utils = Otter::Games::RType::Utils;
    namespace components = Otter::Games::RType::Components;

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void HandleLobby(Otter::Core::Orchestrator& ref, std::vector<std::size_t>&);
} // namespace Otter::Games::RType::System::Lobby

#endif /* !LOBBYSYSTEM_HPP_ */
