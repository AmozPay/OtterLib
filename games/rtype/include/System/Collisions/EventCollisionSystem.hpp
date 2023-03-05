/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventCollisionSystem.hpp
*/

#ifndef RTYPE_EVENTCOLLISIONSYSTEM_HPP
#define RTYPE_EVENTCOLLISIONSYSTEM_HPP

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
     * @brief System for the collision of the entities
     * @details This system is used to check if the second entity is colliding with the first entity
     * @param ref: The orchestrator
     * @param collisions: The collisions components
     * @param transforms: The transforms components
     * @param textures: The textures components
     * @param firstEntityIndex: The index of the first entity
     * @return void
     */
    void SecondEntityCollision(Otter::Core::Orchestrator& ref, auto& collisions, auto& transforms,
                               size_t firstEntityIndex);

    /**
     * @brief Trigger the collision event
     * @details This function is used to trigger the collision event
     * @param ref: The orchestrator
     * @param firstEntityIndex: The index of the first entity
     * @param secondEntityIndex: The index of the second entity
     * @return void
     */
    void TriggerCollision(Otter::Core::Orchestrator& ref, size_t firstEntityIndex, size_t secondEntityIndex);

} // namespace Otter::Games::RType::System::Collision

#endif // RTYPE_COLLISIONSYSTEM_HPP