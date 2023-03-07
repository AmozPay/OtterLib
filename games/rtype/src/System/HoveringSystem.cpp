/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** HoveringSystem
*/

#include "HoveringSystem.hpp"
#include "Components.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::Hovering {

    namespace components = Otter::Core::BaseComponents;

    void Hovering(Otter::Core::Orchestrator& ref)
    {
        auto& hoverings = ref.get_components<Otter::Games::RType::Components::Hovering>();
        const auto& transforms = ref.get_components<components::Transform>();
        auto& velocities = ref.get_components<components::Velocity>();

        for (size_t i = 0; i < hoverings.size() && i < velocities.size() && i < transforms.size(); i++) {
            auto& hovering = hoverings[i];
            auto& velocity = velocities[i];
            const auto& transform = transforms[i];

            if (hovering && velocity && transform) {    
                if (hovering->_direction == Otter::Games::RType::Components::HoveringDirection::DOWN)
                    velocity->_accelerationDirection.y += hovering->_hoveringSpeed;
                if (hovering->_direction == Otter::Games::RType::Components::HoveringDirection::UP)
                    velocity->_accelerationDirection.y -= hovering->_hoveringSpeed;
                if (transform->_position.y > hovering->_maxHovering)
                    hovering->_direction = Otter::Games::RType::Components::HoveringDirection::UP;
                if (transform->_position.y < hovering->_minHovering)
                    hovering->_direction = Otter::Games::RType::Components::HoveringDirection::DOWN;
            }
        }
    }

}