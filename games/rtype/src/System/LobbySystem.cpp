/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** LobbySystem
*/

#include "LobbySystem.hpp"

namespace Otter::Games::RType::System::Lobby {

    using EventPairList = Otter::Games::RType::Components::EventPairList;

    void TriggerInitGame(Otter::Core::Orchestrator& ref)
    {
        auto& gameStatuses = ref.get_components<Otter::Core::BaseComponents::GameStatus>();

        for (size_t i = 0; i < gameStatuses.size(); i++) {
            auto& gameStatus = gameStatuses[i];
            if (!gameStatus)
                continue;
            gameStatus->gameStatusType = Otter::Core::BaseComponents::GAME_INIT;
        }
    }

    void HandleLobby(Otter::Core::Orchestrator& ref, std::vector<std::size_t>&)
    {
        auto &eventNetworks = ref.get_components<Otter::Core::BaseComponents::EventNetwork>();

        for (size_t i = 0; i < eventNetworks.size(); i++) {
            auto& eventNetwork = eventNetworks[i];

            if (!eventNetwork) {
                continue;
            }
            if (eventNetwork->_data == utils::SHOOT) {
                TriggerInitGame(ref);
            }

            eventNetwork->_data = -1;
        }
    }
}
