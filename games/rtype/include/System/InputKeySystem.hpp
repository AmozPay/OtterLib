/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventSystem.hpp
*/

#ifndef RTYPE_KEYEVENTSYSTEM_HPP
#define RTYPE_KEYEVENTSYSTEM_HPP

#include "OtterCore.hpp"
#include "Utils.hpp"

namespace Otter::Games::RType::System::Event {

    /**
     * @brief Poll the event
     * @details Poll the event and manage events
     * @param ref: The orchestrator
     * @return void
     */
    void PollEvent(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::Event

#endif // RTYPE_EVENTSYSTEM_HPP