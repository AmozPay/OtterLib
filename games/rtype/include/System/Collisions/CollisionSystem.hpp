/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.hpp
*/

#ifndef RTYPE_COLLISIONSYSTEM_HPP
#define RTYPE_COLLISIONSYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Collision {

    /**
     * @brief Handle the collision event
     * @details This function is used to handle the collision event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void HandleCollision(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId);

    /**
     * @brief Handle the collision event
     * @details This function is used when there is no player in the collision
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void NonPlayerCollisionHandler(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId);

} // namespace Otter::Games::RType::System::Collision

#endif // RTYPE_COLLISIONSYSTEM_HPP