/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PlayerCollisionSystem.hpp
*/

#ifndef RTYPE_OBSTCLECOLLISIONSYSTEM_HPP
#define RTYPE_OBSTCLECOLLISIONSYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Collision::Obstacle {

    /**
     * @brief Handle the collision event
     * @details This function is used when two obstacles are colliding
     * @param ref: The orchestrator
     * @param vectorId: The vector of the id of the entities
     * @return void
     */
    void ObstacleCollisionHandler(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId);

    /**
     * @brief Handle the collision event
     * @details This function is used when a bullet is colliding with an obstacle
     * @param ref: The orchestrator
     * @param bulletIndex: The index of the bullet
     * @param entityIndex: The index of the entity
     * @param obstacles: The components of the obstacles
     * @return void
     */
    void BulletToEntityCollision(Otter::Core::Orchestrator& ref, size_t bulletIndex, size_t entityIndex,
                                 auto const& obstacles);

    /**
     * @brief Handle the collision event
     * @details This function is used when a wall is colliding with an obstacle
     * @param ref: The orchestrator
     * @param wallIndex: The index of the wall
     * @param entityIndex: The index of the entity
     * @param obstacles: The components of the obstacles
     * @return void
     */
    void WallToEntityCollision(Otter::Core::Orchestrator& ref, size_t wallIndex, size_t entityIndex,
                               auto const& obstacles);

    /**
     * @brief Handle the collision event
     * @details This function is used when a powerup is colliding with an obstacle
     * @param ref: The orchestrator
     * @param powerupIndex: The index of the powerup
     * @param entityIndex: The index of the entity
     * @param obstacles: The components of the obstacles
     * @return void
     */
    void PowerupToEntityCollision(Otter::Core::Orchestrator& ref, size_t powerupIndex, size_t entityIndex,
                                  auto const& obstacles);

    /**
     * @brief Handle the collision event
     * @details This function is used when a bullet is colliding with a wall
     * @param ref: The orchestrator
     * @param bulletIndex: The index of the bullet
     * @param wallIndex: The index of the wall
     * @return void
     */
    void BulletToWallCollision(Otter::Core::Orchestrator& ref, size_t bulletIndex, size_t wallIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used when a bullet is colliding with another bullet
     * @param ref: The orchestrator
     * @param firstBulletIndex: The index of the first bullet
     * @param secondBulletIndex: The index of the second bullet
     * @return void
     */
    void BulletToBulletCollision(Otter::Core::Orchestrator& ref, size_t firstBulletIndex, size_t secondBulletIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used when a bullet is colliding with a powerup
     * @param ref: The orchestrator
     * @param bulletIndex: The index of the bullet
     * @param powerupIndex: The index of the powerup
     * @return void
     */
    void BulletToPowerupCollision(Otter::Core::Orchestrator& ref, size_t bulletIndex, size_t powerupIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used when a wall is colliding with another wall
     * @param ref: The orchestrator
     * @param firstWallIndex: The index of the first wall
     * @param secondWallIndex: The index of the second wall
     * @return void
     */
    void WallToWallCollision(Otter::Core::Orchestrator& ref, size_t firstWallIndex, size_t secondWallIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used when a wall is colliding with a powerup
     * @param ref: The orchestrator
     * @param wallIndex: The index of the wall
     * @param powerupIndex: The index of the powerup
     * @return void
     */
    void WallToPowerupCollision(Otter::Core::Orchestrator& ref, size_t wallIndex, size_t powerupIndex);

    /**
     * @brief Handle the collision event
     * @details This function is used when a powerup is colliding with another powerup
     * @param ref: The orchestrator
     * @param firstPowerupIndex: The index of the first powerup
     * @param secondPowerupIndex: The index of the second powerup
     * @return void
     */
    void PowerupToPowerupCollision(Otter::Core::Orchestrator& ref, size_t firstPowerupIndex, size_t secondPowerupIndex);

} // namespace Otter::Games::RType::System::Collision::Obstacle

#endif // RTYPE_COLLISIONSYSTEM_HPP