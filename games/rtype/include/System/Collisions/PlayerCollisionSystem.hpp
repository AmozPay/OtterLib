/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerCollisionSystem.hpp
*/

#ifndef RTYPE_PLAYERCOLLISIONSYSTEM_HPP
#define RTYPE_PLAYERCOLLISIONSYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Collision::Player {

    /**
     * @brief Handle the collision event
     * @details This function is used when the player is colliding with an entity
     * @param ref: The orchestrator
     * @param playerIndex: The index of the player
     * @param entityIndex: The index of the entity
     * @return void
     */
    void PlayerCollisionHandler(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used to manage the collision between the player and the player
     * @param ref: The orchestrator
     * @param playerIndex: The index of the player
     * @param entityIndex: The index of the entity (player)
     * @return void
     */
    void PlayerToPlayerCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used to manage the collision between the player and the wall
     * @param ref: The orchestrator
     * @param playerIndex: The index of the player
     * @param entityIndex: The index of the entity (wall)
     * @return void
     */
    void PlayerToWallCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used to manage the collision between the player and the bullet
     * @param ref: The orchestrator
     * @param playerIndex: The index of the player
     * @param entityIndex: The index of the entity (bullet)
     * @return void
     */
    void PlayerToBulletCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used to manage the collision between the player and the power up
     * @param ref: The orchestrator
     * @param playerIndex: The index of the player
     * @param entityIndex: The index of the entity (power up)
     * @return void
     */
    void PlayerToPowerUpCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used to manage the collision between the player and the enemy
     * @param ref: The orchestrator
     * @param playerIndex: The index of the player
     * @param entityIndex: The index of the entity (enemy)
     * @return void
     */
    void PlayerToEnemyCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex);

} // namespace Otter::Games::RType::System::Collision::Player

#endif // RTYPE_COLLISIONSYSTEM_HPP