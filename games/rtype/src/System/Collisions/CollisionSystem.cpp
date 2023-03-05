/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "CollisionSystem.hpp"

#include "EnemyCollisionSystem.hpp"
#include "ObstacleCollisionSystem.hpp"
#include "PlayerCollisionSystem.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::Collision {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    void HandleCollision(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId)
    {
        auto const& players = ref.get_components<Otter::Core::BaseComponents::Player>();
        auto const& enemies = ref.get_components<Otter::Core::BaseComponents::Enemy>();

        // At least one of the entities is a player
        if (vectorId.size() == 2) {
            if (vectorId[0] < players.size() && players[vectorId[0]])
                Player::PlayerCollisionHandler(ref, vectorId[0], vectorId[1]);
            else if (vectorId[1] < players.size() && players[vectorId[1]])
                Player::PlayerCollisionHandler(ref, vectorId[1], vectorId[0]);
            else if (vectorId[0] < enemies.size() && enemies[vectorId[0]])
                Enemy::EnemyCollisionHandler(ref, vectorId[0], vectorId[1]);
            else if (vectorId[1] < enemies.size() && enemies[vectorId[1]])
                Enemy::EnemyCollisionHandler(ref, vectorId[1], vectorId[0]);
            else
                Obstacle::ObstacleCollisionHandler(ref, vectorId);
        }
    }

} // namespace Otter::Games::RType::System::Collision