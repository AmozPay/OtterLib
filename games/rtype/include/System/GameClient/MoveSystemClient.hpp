/*
** EPITECH PROJECT, 2023
** RType
** File description:
** MoveSystem.hpp
*/

#ifndef RTYPE_MOVESYSTEMCLIENT_HPP
#define RTYPE_MOVESYSTEMCLIENT_HPP

#include "Components.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "MovePlayerMessageServer.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::GameClient::Move {

    namespace utils = Otter::Games::RType::Utils;
    namespace system = Otter::Games::RType::System;
    namespace baseComponent = Otter::Core::BaseComponents;

    /**
     * @brief System for the movement of the entities
     * @details The movement system is used to move the entities based on their speed, acceleration and direction
     * The acceleration is cleared after the movement
     * @param ref: The orchestrator
     * @return void
     */
    void EntityMovement(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::Move

#endif // RTYPE_MOVESYSTEMCLIENT_HPP