/*
** EPITECH PROJECT, 2023
** RType
** File description:
** MoveSystem.hpp
*/

#ifndef RTYPE_MOVESYSTEM_HPP
#define RTYPE_MOVESYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Move {

    /**
     * @brief System for the movement of the entities
     * @details The movement system is used to move the entities based on their speed, acceleration and direction
     * The acceleration is cleared after the movement
     * @param ref: The orchestrator
     * @return void
     */
    void EntityMovement(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::Move

#endif // RTYPE_MOVESYSTEM_HPP