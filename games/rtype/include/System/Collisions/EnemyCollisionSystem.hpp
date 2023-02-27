/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerCollisionSystem.hpp
*/

#ifndef RTYPE_ENEMYCOLLISIONSYSTEM_HPP
#define RTYPE_ENEMYCOLLISIONSYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Collision::Enemy {

    /**
     * @brief Handle the collision event
     * @details This function is used when an enemy is colliding with an entity
     * @param ref: The orchestrator
     * @param playerIndex: The index of the enemy
     * @param entityIndex: The index of the entity
     * @return void
     */
    void EnemyCollisionHandler(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t entityIndex);

} // namespace Otter::Games::RType::System::Collision::Enemy

#endif // RTYPE_COLLISIONSYSTEM_HPP