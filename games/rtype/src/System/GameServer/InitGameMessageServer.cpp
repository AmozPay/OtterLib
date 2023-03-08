/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** InitGameMessageServer
*/

#include "InitGameMessageServer.hpp"

namespace Otter::Games::RType::System::GameServer::InitGameMessage {

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

    void HandleInitGame(
        Otter::Core::Orchestrator& ref,
        std::string& data,
        int clientId
    ) {
        TriggerInitGame(ref);
    }
} // namespace Otter::Games::RType::System::GameClient::InitGame