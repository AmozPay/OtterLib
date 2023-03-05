/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** CheckClientNbSystem
*/

#include "CheckClientNbSystem.hpp"

namespace Otter::Games::RType::System::CheckClientNb {

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

    void CheckClientNb(Otter::Core::Orchestrator& ref)
    {
        auto &servers = ref.get_components<Otter::Network::ServerComponent>();
        auto &gameStatus = ref.get_components<Otter::Core::BaseComponents::GameStatus>();

        if (!servers[0])
            return;
        
        if (servers[0]->playerId.size() == 0) {
            return;
        }


        for (std::size_t i = 0; i < gameStatus.size(); i++) {
            if (!gameStatus[i])
                continue;
            
            if (gameStatus[i]->gameStatusType == Otter::Core::BaseComponents::LOBBY) {
                std::cout << "There is 1 client !" << std::endl;
                TriggerInitGame(ref);
                std::stringstream notEmptyStream;
                Otter::Network::Sender::broadCast_msg(ref, Otter::Network::MsgCode::INIT_GAME, notEmptyStream);
                std::cout << "Init game sent" << std::endl;
            }
        }
    }

}
