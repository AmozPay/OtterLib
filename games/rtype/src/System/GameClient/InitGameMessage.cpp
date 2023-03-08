/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitGameMessage
*/

#include "InitGameMessage.hpp"

namespace Otter::Games::RType::System::GameClient::InitGameMessage {

    void HandleInitGameMessage(Otter::Core::Orchestrator& ref, std::string&, int)
    {
        auto& gameStatuses = ref.get_components<Otter::Core::BaseComponents::GameStatus>();

        for (size_t i = 0; i < gameStatuses.size(); i++) {
            auto& gameStatus = gameStatuses[i];
            if (!gameStatus)
	      continue;
	    std::stringstream ss;
	    Otter::Games::RType::System::GameClient::SendMessageToServer::Send(ref, Otter::Network::INIT_GAME, ss);
	gameStatus->gameStatusType = Otter::Core::BaseComponents::GAME_INIT;
        }
    }

} // namespace Otter::Games::RType::System::GameClient::InitGameMessage
