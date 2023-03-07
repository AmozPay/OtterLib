/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameStatusSystem
*/

#include "GameStatusSystem.hpp"

namespace Otter::Games::RType::System::GameStatus {

    void TriggerGameEvent(Otter::Core::Orchestrator& ref, components::EventTypes eventType)
    {
        auto& events = ref.get_components<components::EventComponent>();

        for (size_t i = 0; i < events.size(); i++) {
            auto& event = events[i];

            if (!event)
                continue;

            if (event->events.size() == 0) {
                components::EventPair eventPair(eventType, components::ComponentIdVector({}));
                event->events.push_back(eventPair);
            }
        }
    }

    void HandleGameStatus(Otter::Core::Orchestrator& ref)
    {
        auto& statuses = ref.get_components<Core::BaseComponents::GameStatus>();

        for (std::size_t i = 0; i < statuses.size(); i++) {
            if (!statuses[i]) {
                continue;
            }

            if (statuses[i]->gameStatusType == Core::BaseComponents::LOBBY_INIT) {
                TriggerGameEvent(ref, components::EventTypes::INIT_LOBBY);
            }

            if (statuses[i]->gameStatusType == Core::BaseComponents::LOBBY) {
                TriggerGameEvent(ref, components::EventTypes::LOBBY);
            }

            if (statuses[i]->gameStatusType == Core::BaseComponents::GAME_INIT) {
                TriggerGameEvent(ref, components::EventTypes::INIT_GAME);
            }

            if (statuses[i]->gameStatusType == Core::BaseComponents::GAME_OVER) {
                std::cout << "Game over" << std::endl;
                TriggerGameEvent(ref, components::EventTypes::GAME_OVER);
            }

            if (statuses[i]->gameStatusType == Core::BaseComponents::WIN) {
                TriggerGameEvent(ref, components::EventTypes::WIN);
            }
        }
    }
} // namespace Otter::Games::RType::System::GameStatus
