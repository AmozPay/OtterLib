/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "ObstacleCollisionSystem.hpp"

namespace Otter::Games::RType::System::Collision::Obstacle {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    void BulletToWallCollision(Otter::Core::Orchestrator& ref, size_t bulletIndex, size_t wallIndex) {}

    void BulletToBulletCollision(Otter::Core::Orchestrator& ref, size_t firstBulletIndex, size_t secondBulletIndex) {}

    void BulletToPowerupCollision(Otter::Core::Orchestrator& ref, size_t bulletIndex, size_t powerupIndex) {}

    void WallToWallCollision(Otter::Core::Orchestrator& ref, size_t firstWallIndex, size_t secondWallIndex) {}

    void WallToPowerupCollision(Otter::Core::Orchestrator& ref, size_t wallIndex, size_t powerupIndex) {}

    void PowerupToPowerupCollision(Otter::Core::Orchestrator& ref, size_t firstPowerupIndex, size_t secondPowerupIndex)
    {
    }

    void WallToEntityCollision(Otter::Core::Orchestrator& ref, size_t wallIndex, size_t entityIndex,
                               auto const& obstacles)
    {
        if (entityIndex < obstacles.size() && obstacles[entityIndex]) {
            auto const& obstacle = obstacles[entityIndex];

            if (obstacle->_type == components::WALL)
                WallToWallCollision(ref, wallIndex, entityIndex);
            if (obstacle->_type == components::BULLET)
                BulletToWallCollision(ref, wallIndex, entityIndex);
            if (obstacle->_type == components::POWERUP)
                WallToPowerupCollision(ref, wallIndex, entityIndex);
        }
    }

    void BulletToEntityCollision(Otter::Core::Orchestrator& ref, size_t bulletIndex, size_t entityIndex,
                                 auto const& obstacles)
    {
        if (entityIndex < obstacles.size() && obstacles[entityIndex]) {
            auto const& obstacle = obstacles[entityIndex];

            if (obstacle->_type == components::WALL)
                BulletToWallCollision(ref, bulletIndex, entityIndex);
            if (obstacle->_type == components::BULLET)
                BulletToBulletCollision(ref, bulletIndex, entityIndex);
            if (obstacle->_type == components::POWERUP)
                BulletToPowerupCollision(ref, bulletIndex, entityIndex);
        }
    }

    void PowerupToEntityCollision(Otter::Core::Orchestrator& ref, size_t powerupIndex, size_t entityIndex,
                                  auto const& obstacles)
    {
        if (entityIndex < obstacles.size() && obstacles[entityIndex]) {
            auto const& obstacle = obstacles[entityIndex];

            if (obstacle->_type == components::WALL)
                WallToPowerupCollision(ref, powerupIndex, entityIndex);
            if (obstacle->_type == components::BULLET)
                BulletToPowerupCollision(ref, powerupIndex, entityIndex);
            if (obstacle->_type == components::POWERUP)
                PowerupToPowerupCollision(ref, powerupIndex, entityIndex);
        }
    }

    void ObstacleCollisionHandler(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId)
    {
        auto const& obstacles = ref.get_components<components::Obstacle>();

        if (vectorId[0] < obstacles.size() && obstacles[vectorId[0]]) {
            auto const& obstacle = obstacles[vectorId[0]];

            if (obstacle->_type == components::WALL)
                WallToEntityCollision(ref, vectorId[0], vectorId[1], obstacles);
            if (obstacle->_type == components::BULLET)
                BulletToEntityCollision(ref, vectorId[0], vectorId[1], obstacles);
            if (obstacle->_type == components::POWERUP)
                PowerupToEntityCollision(ref, vectorId[0], vectorId[1], obstacles);
        }
    }

} // namespace Otter::Games::RType::System::Collision::Obstacle