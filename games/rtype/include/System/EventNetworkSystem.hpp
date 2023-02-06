/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventNetworkSystem.hpp
*/

#ifndef RTYPE_EVENTNETWORKSYSTEM_HPP
#define RTYPE_EVENTNETWORKSYSTEM_HPP

#include "OtterCore.hpp"
#include "Utils.hpp"

namespace Otter::Games::RType::System::EventNetwork {

    void PlayerMovementEvent(auto& velocity, Otter::Games::RType::Utils::EventState state);

    void CreateShot(Otter::Core::Orchestrator& ref, size_t playerIndex);

    void EventHandler(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::EventNetwork

#endif // RTYPE_EVENTNETWORKSYSTEM_HPP