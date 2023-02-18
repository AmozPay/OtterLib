/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "EnemyCollisionSystem.hpp"

namespace Otter::Games::RType::System::Collision::Enemy {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    void EnemyToEnemyCollision(Otter::Core::Orchestrator& ref, size_t firstEnemyIndex, size_t secondEnemyIndex)
    {
        std::cout << "Enemy to Enemy" << std::endl;
    }

    void EnemyToWallCollision(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t wallIndex)
    {
        std::cout << "Enemy to Wall" << std::endl;
    }

    void EnemyToBulletCollision(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t bulletIndex)
    {
        auto const& damages = ref.get_components<components::Damage>();
        auto& healths = ref.get_components<components::Health>();
        auto const& shots = ref.get_components<components::Shot>();

        if (enemyIndex < healths.size() && healths[enemyIndex] && bulletIndex < shots.size() && shots[bulletIndex]) {
            auto const shot = shots[bulletIndex];
            if (shot->_shooterId < damages.size() && damages[shot->_shooterId]) {
                if (healths[enemyIndex]->_hp - damages[shot->_shooterId]->_damage > 0)
                    healths[enemyIndex]->_hp -= damages[shot->_shooterId]->_damage;
                else
                    healths[enemyIndex]->_hp = 0;

                std::cout << healths[enemyIndex]->_hp << std::endl;
            }
        }
        ref.remove_component<components::Render>(bulletIndex);
        ref.remove_component<components::BoxCollider>(bulletIndex);
        std::cout << "Enemy to Bullet" << std::endl;
    }

    void EnemyToPowerUpCollision(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t powerupIndex)
    {
        std::cout << "Enemy to Powerup" << std::endl;
    }

    void EnemyCollisionHandler(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t entityIndex)
    {
        auto const& obstacles = ref.get_components<components::Obstacle>();
        auto const& enemies = ref.get_components<components::Enemy>();

        if (entityIndex < enemies.size() && enemies[entityIndex])
            EnemyToEnemyCollision(ref, enemyIndex, entityIndex);
        if (entityIndex < obstacles.size() && obstacles[entityIndex]) {
            auto const& obstacle = obstacles[entityIndex];
            if (obstacle->_type == components::WALL)
                EnemyToWallCollision(ref, enemyIndex, entityIndex);
            if (obstacle->_type == components::BULLET)
                EnemyToBulletCollision(ref, enemyIndex, entityIndex);
            if (obstacle->_type == components::POWERUP)
                EnemyToPowerUpCollision(ref, enemyIndex, entityIndex);
        }
    }

} // namespace Otter::Games::RType::System::Collision::Enemy