/*
** EPITECH PROJECT, 2023
** RType
** File description:
** MoveSystem.cpp
*/

#include "MoveSystem.hpp"

namespace Otter::Games::RType::System::Move {

    void EntityMovement(Otter::Core::Orchestrator& ref)
    {
        auto& transforms = ref.get_components<Otter::Games::RType::Components::Transform>();
        auto& velocities = ref.get_components<Otter::Games::RType::Components::Velocity>();
        for (size_t i = 0; i < transforms.size() && i < velocities.size(); i++) {
            auto& transform = transforms[i];
            auto& velocity = velocities[i];
            if (transform && velocity) {
                transform->position.x += velocity->accelerationDirection.x * velocity->speed;
                transform->position.y += velocity->accelerationDirection.y * velocity->speed;
                velocity->accelerationDirection.x = 0;
                velocity->accelerationDirection.y = 0;
            }
        }
    }
} // namespace Otter::Games::RType::System::Move