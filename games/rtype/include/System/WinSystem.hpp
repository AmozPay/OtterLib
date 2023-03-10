/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** WinSystem
*/

#ifndef WINSYSTEM_HPP_
#define WINSYSTEM_HPP_

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::Win {
    namespace utils = Otter::Games::RType::Utils;
    namespace components = Otter::Games::RType::Components;

    void CheckWin(Otter::Core::Orchestrator& ref);

    /**
     * @brief Handle the lobby event
     * @details This function is used to handle the lobby event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void HandleWin(Otter::Core::Orchestrator& ref, std::vector<std::size_t>&);

} // namespace Otter::Games::RType::System::Win

#endif /* !WINSYSTEM_HPP_ */
