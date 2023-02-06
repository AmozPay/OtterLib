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

                transform->_lastPosition = transform->_position;
                if (velocity->_accelerationDirection.x == 0)
                    transform->_position.x += velocity->_constantAccelerationDirection.x * velocity->_constantSpeed;
                if (velocity->_accelerationDirection.y == 0)
                    transform->_position.y += velocity->_constantAccelerationDirection.y * velocity->_constantSpeed;
                transform->_position.x += velocity->_accelerationDirection.x * velocity->_speed;
                transform->_position.y += velocity->_accelerationDirection.y * velocity->_speed;
                velocity->_accelerationDirection.x = 0;
                velocity->_accelerationDirection.y = 0;
            }
        }
    }
} // namespace Otter::Games::RType::System::Move
