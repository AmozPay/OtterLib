/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventSystem.hpp
*/

#ifndef RTYPE_EVENTSYSTEM_HPP
#define RTYPE_EVENTSYSTEM_HPP

#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Event {

    /**
     * @brief Poll the event
     * @details Poll the event and manage events
     * @param ref: The orchestrator
     * @return void
     */
    void PollEvent(Otter::Core::Orchestrator& ref);

    /**
     * @brief Manage the player movement
     * @details Manage the player movement with the velocity and the key pressed to move in the right direction
     * @param velocity: The velocity of the player (x and y)
     * @param keyPressed: The key pressed
     * @return void
     */
    void PlayerMovementEvent(auto& velocity, int keyPressed);
} // namespace Otter::Games::RType::System::Event

#endif // RTYPE_EVENTSYSTEM_HPP