/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "EnemyCollisionSystem.hpp"

#include "PlayerCollisionSystem.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::Collision::Enemy {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;
    namespace systems = Otter::Games::RType::System;

    void EnemyToEnemyCollision(Otter::Core::Orchestrator& ref, size_t firstEnemyIndex, size_t secondEnemyIndex)
    {
        std::cout << "Enemy to Enemy" << std::endl;
    }

    void EnemyToWallCollision(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t wallIndex)
    {
        auto& healths = ref.get_components<Otter::Core::BaseComponents::Health>();
        auto const& damages = ref.get_components<Otter::Core::BaseComponents::Damage>();
        auto& players = ref.get_components<Otter::Core::BaseComponents::Player>();

        if (enemyIndex < healths.size() && healths[enemyIndex]) {
            healths[enemyIndex]->_hp = 0;
        }

        // for (std::size_t i = 0; i < players.size(); i++)
        // {
        //     if (!players[i])
        //         continue;

        //     systems::Collision::Player::PlayerToEnemyCollision(ref, i, enemyIndex);
        // }

        std::cout << "Enemy to Wall" << std::endl;
    }

    void EnemyToBulletCollision(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t bulletIndex)
    {
        auto const& damages = ref.get_components<Otter::Core::BaseComponents::Damage>();
        auto& healths = ref.get_components<Otter::Core::BaseComponents::Health>();
        auto const& shots = ref.get_components<components::Shot>();

        std::cout << "Enemy index " << enemyIndex << std::endl;
        std::cout << "Bullet index " << bulletIndex << std::endl;

        if (enemyIndex < healths.size() && healths[enemyIndex] && bulletIndex < shots.size() && shots[bulletIndex]) {
            auto const shot = shots[bulletIndex];

            if (shot->_shooterId < damages.size() && damages[shot->_shooterId]) {
                healths[enemyIndex]->_hp = healths[enemyIndex]->_hp - damages[shot->_shooterId]->_damage;

                if (healths[enemyIndex]->_hp <= 0)
                    healths[enemyIndex]->_hp = 0;

                std::cout << healths[enemyIndex]->_hp << std::endl;
            }
        }
        // TODO: need to delete the entity
        ref.remove_entity(static_cast<std::uint32_t>(bulletIndex));
        std::cout << "Enemy to Bullet" << std::endl;
    }

    void EnemyToPowerUpCollision(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t powerupIndex)
    {
        std::cout << "Enemy to Powerup" << std::endl;
    }

    void EnemyCollisionHandler(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t entityIndex)
    {
        auto const& obstacles = ref.get_components<components::Obstacle>();
        auto const& enemies = ref.get_components<Otter::Core::BaseComponents::Enemy>();

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