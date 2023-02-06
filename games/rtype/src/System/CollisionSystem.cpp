/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "CollisionSystem.hpp"

namespace Otter::Games::RType::System::Collision {

    void ApplyChange(auto& health, auto& transform)
    {
        // The entity is moving to the right
        if (transform->_position->x - transform->_lastPosition.x > 0) {
            health->_hp = 0;
            std::cout << "RIGHT COLLISION" << std::endl;
            // reset pos
        }
        transform->_position = transform->_lastPosition;
    }

    void EntityCollision(Otter::Core::Orchestrator& ref)
    {
        auto const& collisions = ref.get_components<Otter::Games::RType::Components::BoxCollider>();
        auto const& players = ref.get_components<Otter::Games::RType::Components::Player>();
        auto& transforms = ref.get_components<Otter::Games::RType::Components::Transform>();
        auto const& textures = ref.get_components<Otter::Games::RType::Components::Texture>();
        auto& healths = ref.get_components<Otter::Games::RType::Components::Health>();

        for (size_t i = 0; i < collisions.size() && i < transforms.size() && i < textures.size(); i++) {
            auto const& collisionFirst = collisions[i];
            auto& transformFirst = transforms[i];
            auto const& textureFirst = textures[i];
            if (!collisionFirst || !transformFirst || !textureFirst)
                continue;
            for (size_t j = 0; j < collisions.size() && j < transforms.size() && j < textures.size(); j++) {
                if (j == i)
                    continue;
                auto const& collisionsSecond = collisions[j];
                auto& transformSecond = transforms[j];
                auto const& playerFirst = players[i];
                auto const& textureSecond = textures[j];
                auto& healthFirst = healths[i];
                if (collisionsSecond && transformSecond && textureSecond) {
                    if (playerFirst) {
                        bool collision = textureFirst->_texture.checkCollisionRecs(
                            {transformFirst->_position->x, transformFirst->_position->y, collisionFirst->_width,
                             collisionFirst->_height},
                            {transformSecond->_position->x, transformSecond->_position->y, collisionsSecond->_width,
                             collisionsSecond->_height});
                        if (collision) {
                            if (playerFirst) {
                                ApplyChange(healthFirst, transformFirst);
                            }
                        }
                    }
                }
            }
        }
    }

} // namespace Otter::Games::RType::System::Collision