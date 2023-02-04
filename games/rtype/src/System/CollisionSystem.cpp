/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "CollisionSystem.hpp"

namespace Otter::Games::RType::System::Collision {

    CollisionDirection collisionDirection(const Otter::Games::RType::Components::BoxCollider col1,
                                          const Otter::Games::RType::Components::BoxCollider col2,
                                          const Otter::Games::RType::Components::Transform trans1,
                                          const Otter::Games::RType::Components::Transform trans2)
    {
        if (trans1._position.x + col1.width < trans2._position.x + col2.width &&
            trans1._position.x + col1.width > trans2._position.x) {
            return CollisionDirection::RIGHT;
        } else if (trans1._position.x < trans2._position.x + col2.width && trans1._position.x > trans2._position.x) {
            return CollisionDirection::LEFT;
        } else if (trans1._position.y < trans2._position.y + col2.height && trans1._position.y > trans2._position.y) {
            return CollisionDirection::TOP;
        } else {
            return CollisionDirection::BOTTOM;
        }
    }

    void apllyChange(CollisionDirection direction, Otter::Games::RType::Components::Player player,
                     Otter::Games::RType::Components::Health health, Otter::Games::RType::Components::Transform trans,
                     Otter::Games::RType::Components::BoxCollider col2,
                     Otter::Games::RType::Components::Transform trans2)
    {
        if (direction == RIGHT) {
            health.hp = 0;
            // reset pos
        } else if (direction == LEFT) {
            trans._position.x = trans2._position.x + col2.width;
        } else if (direction == TOP) {
            trans._position.y = trans2._position.y + col2.height;
        } else {
            trans._position.y = trans2._position.y - col2.height;
        }
    }

    void EntityCollision(Otter::Core::Orchestrator& ref)
    {
        auto const& collisions = ref.get_components<Otter::Games::RType::Components::BoxCollider>();
        auto const& player = ref.get_components<Otter::Games::RType::Components::Player>();
        auto const& transform = ref.get_components<Otter::Games::RType::Components::Transform>();
        auto const& texture = ref.get_components<Otter::Games::RType::Components::Texture>();
        auto const& health = ref.get_components<Otter::Games::RType::Components::Health>();

        for (size_t i = 0; i < collisions.size(); i++) {
            for (size_t j = 0; j < collisions.size(); j++) {
                auto const& colI = collisions[i];
                auto const& colJ = collisions[j];
                auto const& transI = transform[i];
                auto const& transJ = transform[j];
                auto const& playerI = player[i];
                auto const& playerJ = player[j];
                auto const& texI = texture[i];
                auto const& texJ = texture[j];
                auto const& helthI = health[i];
                auto const& helthJ = health[j];
                if (transI && transJ && colI && colJ && texI && texJ) {
                    if (playerI || playerJ) {
                        bool collision = texI->_texture.checkCollisionRecs(
                            {transI->_position.x, transI->_position.y, colI->width, colI->height},
                            {transJ->_position.x, transJ->_position.y, colJ->width, colJ->height});
                        if (collision) {
                            CollisionDirection side = collisionDirection(*colI, *colJ, *transI, *transJ);
                            if (playerI) {
                                apllyChange(side, *playerI, *helthI, *transI, *colJ, *transJ);
                            } else {
                                apllyChange(side, *playerJ, *helthJ, *transJ, *colI, *transI);
                            }
                        }
                    }
                }
            }
        }
    }

} // namespace Otter::Games::RType::System::Collision