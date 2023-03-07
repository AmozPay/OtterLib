/*
** EPITECH PROJECT, 2023
** RType
** File description:
** DeathSystem.cpp
*/

#include "DeathSystem.hpp"

#include "GameOverSystem.hpp"
#include "baseComponents.hpp"

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
        auto const& players = ref.get_components<Otter::Core::BaseComponents::Player>();

        for (size_t i = 0; i < healths.size(); i++) {
            auto const& health = healths[i];
            auto& player = players[i];

            if (health && health->_hp <= 0) {
                TriggerDeath(ref, i);
                if (player)
                    std::cout << "death player triggerd" << std::endl;
            }
        }
    }

    void HandleHealthTextDelete(Otter::Core::Orchestrator& ref, int entityId)
    {
        auto& entityHealthTexts = ref.get_components<Otter::Core::BaseComponents::Text>();

        for (size_t i = 0; i < entityHealthTexts.size(); i++) {
            auto& entityHealthText = entityHealthTexts[i];

            if (entityHealthText && entityHealthText->_linkedEntityId == entityId)
                ref.remove_entity(static_cast<std::uint32_t>(i));
        }
    }

    void HandleDeathServer(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId)
    {
        auto& players = ref.get_components<Otter::Core::BaseComponents::Player>();
        auto& enemies = ref.get_components<Otter::Core::BaseComponents::Enemy>();

        for (auto& id : vectorId) {
            if (players[id] || enemies[id]) {
                ref.remove_entity(static_cast<std::uint32_t>(id));
                std::cout << "Remove entity" << std::endl;
            }
        }
    }

    void HandleDeathClient(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId)
    {
        auto& animationComp = ref.get_components<components::AnimationComponent>();
        auto& players = ref.get_components<Otter::Core::BaseComponents::Player>();

        for (auto& id : vectorId) {
            HandleHealthTextDelete(ref, id);
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