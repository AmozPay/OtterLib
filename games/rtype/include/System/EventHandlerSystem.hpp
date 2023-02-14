/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** EventHandlerSystem
*/

#ifndef EVENTHANDLERSYSTEM_HPP_
#define EVENTHANDLERSYSTEM_HPP_

#include "OtterCore.hpp"

namespace Otter::Games::RType::System::EventHandler {

    /**
     * @brief System for handling customs events
     * @details The event handler system is used to call function when an event is triggered
     * @param ref: The orchestrator
     * @return void
     */
    void EventHandlerSystem(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::Collision

#endif /* !EVENTHANDLERSYSTEM_HPP_ */
