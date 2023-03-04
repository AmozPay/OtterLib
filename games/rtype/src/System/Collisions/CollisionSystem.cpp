/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "baseComponents.hpp"
#include "CollisionSystem.hpp"

#include "EnemyCollisionSystem.hpp"
#include "ObstacleCollisionSystem.hpp"
#include "PlayerCollisionSystem.hpp"

namespace Otter::Games::RType::System::Collision {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    void PlayerToEnemyCollision(Otter::Core::Orchestrator& ref, size_t playerIndex, size_t entityIndex)
    {
        auto& healths = ref.get_components<Otter::Core::BaseComponents::Health>();
        auto const& damages = ref.get_components<Otter::Core::BaseComponents::Damage>();

        if (playerIndex < healths.size() && healths[playerIndex] && entityIndex < damages.size() &&
            damages[entityIndex]) {
            if (damages[entityIndex]->_damage < healths[playerIndex]->_hp)
                healths[playerIndex]->_hp -= damages[entityIndex]->_damage;
            else
                healths[playerIndex]->_hp = 0;
        }
        std::cout << "Player to Enemy" << std::endl;
    }

    void EnemyToBulletCollision(Otter::Core::Orchestrator& ref, size_t enemyIndex, size_t bulletIndex)
    {
        auto const& damages = ref.get_components<Otter::Core::BaseComponents::Damage>();
        auto& healths = ref.get_components<Otter::Core::BaseComponents::Health>();
        auto const& shots = ref.get_components<components::Shot>();

        if (enemyIndex < healths.size() && healths[enemyIndex] && bulletIndex < shots.size() && shots[bulletIndex]) {
            auto const shot = shots[bulletIndex];

            if (shot->_shooterId < damages.size() && damages[shot->_shooterId]) {
                healths[enemyIndex]->_hp = healths[enemyIndex]->_hp - damages[shot->_shooterId]->_damage;
                
                if (healths[enemyIndex]->_hp <= 0)
                    healths[enemyIndex]->_hp = 0;
            }
        }
        // TODO: need to delete the entity
        ref.remove_entity(static_cast<std::uint32_t>(bulletIndex));
        std::cout << "Enemy to Bullet" << std::endl;
    }

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