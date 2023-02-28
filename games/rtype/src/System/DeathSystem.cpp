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
        for (auto &id: vectorId) {
            auto &animationComp = ref.get_components<components::AnimationComponent>();

            if (!animationComp[id]) {
                ref.remove_entity(static_cast<std::uint32_t>(id));
                std::cout << "Entity remove" << std::endl;
                break;
            }

            if (!animationComp[id]->idAnimMap.contains(components::DEATH_ANIM)) {
                ref.remove_entity(static_cast<std::uint32_t>(id));
                std::cout << "Entity remove" << std::endl;
                break;
            }

            if (animationComp[id]->currentAnim != components::DEATH_ANIM) {
                animationComp[id]->currentAnim = components::DEATH_ANIM;
                continue;
            }

            auto animation = animationComp[id]->idAnimMap.find(components::DEATH_ANIM)->second;

            if (animation.currentPos >= animation.animVect.size() - 1) {
                ref.remove_entity(static_cast<std::uint32_t>(id));
                std::cout << "Entity remove" << std::endl;
                break;
            }

        }

    }

} // namespace Otter::Games::RType::System::Death