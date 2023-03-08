/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** DecelerationSystem
*/

#include "Components.hpp"
#include "baseComponents.hpp"
#include "DecelerationSystem.hpp"

namespace Otter::Games::RType::System::Deceleration {

    namespace components = Otter::Games::RType::Components;

    void Deceleration(Otter::Core::Orchestrator& ref) 
    {
        const auto& decelerations = ref.get_components<components::Deceleration>();
        const auto& transforms = ref.get_components<Otter::Core::BaseComponents::Transform>();
        auto& velocities = ref.get_components<Otter::Core::BaseComponents::Velocity>();

        for (size_t i = 0; i < decelerations.size() && i < transforms.size() && i < velocities.size(); i++) {
            const auto& deceleration = decelerations[i];
            const auto& transform = transforms[i];
            auto& velocity = velocities[i];

            if (deceleration && transform && velocity) {
                if (transform->_position.x <= deceleration->_triggeredPosition) {
                    if (velocity->_constantSpeed > deceleration->_decelerationValue)
                        velocity->_constantSpeed -= deceleration->_decelerationValue;
                    else
                        velocity->_constantSpeed = 0;
                }
            }
        }
    }

}
