/*
** EPITECH PROJECT, 2023
** RType
** File description:
** MoveSystem.cpp
*/

#include "MoveSystemServer.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::GameServer::Move {

    void sendPlayerMovement(
        Otter::Core::Orchestrator& ref,
        std::size_t &playerIndex,
        utils::Vector2 &pos
    ) {
        auto &players = ref.get_components<baseComponent::Player>();

        if (playerIndex >= players.size())
            return;
        if (!players[playerIndex])
            return;

        system::GameServer::MovePlayerMessage::SendMovePlayerMessage(
            ref,
            players[playerIndex]->_id,
            pos
        );
    }

    void sendEnemyMovement(
        Otter::Core::Orchestrator& ref,
        std::size_t &enemyIndex,
        utils::Vector2 &pos
    ) {
        auto &enemies = ref.get_components<baseComponent::Enemy>();

        if (enemyIndex >= enemies.size())
            return;
        if (!enemies[enemyIndex])
            return;

        system::GameServer::MoveEnemyMessage::SendMoveEnemyMessage(
            ref,
            enemies[enemyIndex]->_id,
            pos
        );
    }

    void EntityMovement(Otter::Core::Orchestrator& ref)
    {
        auto& transforms = ref.get_components<Otter::Core::BaseComponents::Transform>();
        auto& velocities = ref.get_components<Otter::Core::BaseComponents::Velocity>();

        for (size_t i = 0; i < transforms.size() && i < velocities.size(); i++) {
            auto& transform = transforms[i];
            auto& velocity = velocities[i];
            if (transform && velocity) {
                transform->_lastPosition = transform->_position;
                if (velocity->_accelerationDirection.x == 0)
                    transform->_position.x += velocity->_constantAccelerationDirection.x * velocity->_constantSpeed;
                if (velocity->_accelerationDirection.y == 0)
                    transform->_position.y += velocity->_constantAccelerationDirection.y * velocity->_constantSpeed;
                transform->_position.x += velocity->_accelerationDirection.x * velocity->_speed;
                transform->_position.y += velocity->_accelerationDirection.y * velocity->_speed;
                velocity->_accelerationDirection.x = 0;
                velocity->_accelerationDirection.y = 0;
                sendPlayerMovement(ref, i, transform->_position);
            }
        }
    }
} // namespace Otter::Games::RType::System::Move