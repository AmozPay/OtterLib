/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "PlayerCollisionSystem.hpp"

namespace Otter::Games::RType::System::Collision::Player {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    void PlayerToPlayerCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex)
    {
        std::cout << "Player to Player" << std::endl;
    }

    void PlayerToWallCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex)
    {
        auto& transforms = ref.get_components<components::Transform>();
        auto& healths = ref.get_components<components::Health>();

        if (playerIndex < transforms.size() && playerIndex < healths.size()) {
            auto& playerTransform = transforms[playerIndex];
            auto& playerHealth = healths[playerIndex];

            if (playerTransform->_position.x - playerTransform->_lastPosition.x > 0)
                playerHealth->_hp = 0;
            playerTransform->_position = playerTransform->_lastPosition;
        }
        std::cout << "Player to Wall" << std::endl;
    }

    void PlayerToBulletCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex)
    {
        std::cout << "Player to Bullet" << std::endl;
    }

    void PlayerToPowerUpCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex)
    {
        std::cout << "Player to Power UP" << std::endl;
    }

    void PlayerToEnemyCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex)
    {
        auto& healths = ref.get_components<components::Health>();
        auto const& damages = ref.get_components<components::Damage>();

        if (playerIndex < healths.size() && healths[playerIndex] && entityIndex < damages.size() &&
            damages[entityIndex]) {
            if (damages[entityIndex]->_damage < healths[playerIndex]->_hp)
                healths[playerIndex]->_hp -= damages[entityIndex]->_damage;
            else
                healths[playerIndex]->_hp = 0;
        }
        std::cout << "Player to Enemy" << std::endl;
    }

    void PlayerCollisionHandler(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex)
    {
        auto const& obstacles = ref.get_components<components::Obstacle>();
        auto const& players = ref.get_components<components::Player>();
        auto const& enemies = ref.get_components<components::Enemy>();

        if (entityIndex < players.size() && players[entityIndex])
            PlayerToPlayerCollision(ref, playerIndex, entityIndex);
        if (entityIndex < enemies.size() && enemies[entityIndex])
            PlayerToEnemyCollision(ref, playerIndex, entityIndex);
        if (entityIndex < obstacles.size() && obstacles[entityIndex]) {
            auto const& obstacle = obstacles[entityIndex];
            if (obstacle->_type == components::ObstacleType::WALL)
                PlayerToWallCollision(ref, playerIndex, entityIndex);
            if (obstacle->_type == components::ObstacleType::BULLET)
                PlayerToBulletCollision(ref, playerIndex, entityIndex);
            if (obstacle->_type == components::ObstacleType::POWERUP)
                PlayerToPowerUpCollision(ref, playerIndex, entityIndex);
        }
    }

} // namespace Otter::Games::RType::System::Collision::Player