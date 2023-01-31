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

    void PollEvent(Otter::Core::Orchestrator& ref);

    void PlayerMovementEvent(auto& velocity, int keyPressed);
} // namespace Otter::Games::RType::System::Event

#endif // RTYPE_EVENTSYSTEM_HPP