/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "CollisionSystem.hpp"

#include "PlayerCollisionSystem.hpp"

namespace Otter::Games::RType::System::Collision {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    void ApplyChange(auto& health, auto& transform)
    {
        // The entity is moving to the right
        if (transform->_position.x - transform->_lastPosition.x > 0) {
            health->_hp = 0;
            std::cout << "RIGHT COLLISION" << std::endl;
            // reset pos
        }
        transform->_position = transform->_lastPosition;
    }

    void NonPlayerCollisionHandler(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId) {}

    void HandleCollision(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId)
    {
        auto const& players = ref.get_components<components::Player>();

        // At least one of the entities is a player
        if (vectorId.size() == 2) {
            if (vectorId[0] < players.size() && players[vectorId[0]])
                Player::PlayerCollisionHandler(ref, vectorId[0], vectorId[1]);
            else if (vectorId[1] < players.size() && players[vectorId[1]])
                Player::PlayerCollisionHandler(ref, vectorId[1], vectorId[0]);
            else
                NonPlayerCollisionHandler(ref, vectorId);
        }
    }

} // namespace Otter::Games::RType::System::Collision