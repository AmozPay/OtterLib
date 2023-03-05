/*
** EPITECH PROJECT, 2023
** RType
** File description:
** DeathSystem.cpp
*/

#include "baseComponents.hpp"
#include "DeathSystem.hpp"
#include "GameOverSystem.hpp"

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

    void HandlePlayerDeath(Otter::Core::Orchestrator& ref, std::size_t playerIndex)
    {
        auto &players = ref.get_components<Otter::Core::BaseComponents::Player>();

        if (playerIndex > players.size())
            return;
        if (!players[playerIndex])
            return;
        Otter::Games::RType::System::GameOver::TriggerGameOver(ref);
    }

    void HandleDeath(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId)
    {
        auto &animationComp = ref.get_components<components::AnimationComponent>();
        auto &players = ref.get_components<Otter::Core::BaseComponents::Player>();

        for (auto &id: vectorId) {
            

            if (!animationComp[id]) {
                if (players[id])
                    Otter::Games::RType::System::GameOver::TriggerGameOver(ref);
                else
                    ref.remove_entity(static_cast<std::uint32_t>(id));
                std::cout << "Entity remove" << std::endl;
                break;
            }

            if (!animationComp[id]->idAnimMap.contains(components::DEATH_ANIM)) {
                if (players[id])
                    Otter::Games::RType::System::GameOver::TriggerGameOver(ref);
                else
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
                if (players[id])
                    Otter::Games::RType::System::GameOver::TriggerGameOver(ref);
                else
                    ref.remove_entity(static_cast<std::uint32_t>(id));
                std::cout << "Entity remove" << std::endl;
                break;
            }

        }

    }

} // namespace Otter::Games::RType::System::Death