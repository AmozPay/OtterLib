/*
** EPITECH PROJECT, 2023
** RType
** File description:
** DeathSystem.cpp
*/

#include "baseComponents.hpp"
#include "DeathSystem.hpp"

namespace Otter::Games::RType::System::Death {

    namespace components = Otter::Games::RType::Components;

    void TriggerDeath(Otter::Core::Orchestrator& ref, size_t entityIndex)
    {
        auto& events = ref.get_components<components::EventComponent>();

        for (size_t i = 0; i < events.size(); i++) {
            auto& event = events[i];
            if (event) {
                components::EventPair eventPair(components::EventTypes::DEATH,
                                                components::ComponentIdVector({entityIndex}));
                event->events.push_back(eventPair);
            }
        }
    }

    void EntityDeath(Otter::Core::Orchestrator& ref)
    {
        auto const& healths = ref.get_components<Otter::Core::BaseComponents::Health>();

        for (size_t i = 0; i < healths.size(); i++) {
            auto const& health = healths[i];

            if (health && health->_hp <= 0)
                TriggerDeath(ref, i);
        }
    }

    void HandleDeath(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId)
    {
        std::cout << "Entity dead" << std::endl;
    }

} // namespace Otter::Games::RType::System::Death