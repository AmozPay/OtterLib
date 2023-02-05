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
     * @brief System for the collision of the entities
     * @details The collision system is used to check if the entities are colliding with each other
     * @param ref: The orchestrator
     * @return void
     */
    void EntityCollision(Otter::Core::Orchestrator& ref);

    /**
     * @brief Apply changes due to collision
     * @details If the entity is a player, the health is decreased to 0 if the collision is on the right. Otherwise, the
     * position is reset to the last checkpoint
     * @param health: The health of the entity
     * @param transform: The transform of the entity
     * @return void
     */
    void ApplyChange(auto& health, auto& transform);
} // namespace Otter::Games::RType::System::Collision

#endif // RTYPE_COLLISIONSYSTEM_HPP