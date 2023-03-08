/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** WinSystem
*/

#include "WinSystemServer.hpp"

namespace Otter::Games::RType::System::GameServer::Win {
    void InitWinScene(Otter::Core::Orchestrator& ref)
    {
        auto& players = ref.get_components<Otter::Core::BaseComponents::Player>();
        auto& velocities = ref.get_components<Otter::Core::BaseComponents::Velocity>();

        for (std::size_t i = 0; i < players.size() || i < velocities.size(); i++) {
            if (players[i] && velocities[i]) {
                ref.remove_component<Otter::Core::BaseComponents::Velocity>(static_cast<std::uint32_t>(i));
            }
        }
    }

    void TriggerWin(Otter::Core::Orchestrator& ref)
    {
        auto& gameStatus = ref.get_components<Otter::Core::BaseComponents::GameStatus>();

        for (std::size_t i = 0; i < gameStatus.size(); i++) {
            if (!gameStatus[i])
                continue;
            if (gameStatus[i]->gameStatusType != Otter::Core::BaseComponents::GAME)
                return;
            gameStatus[i]->gameStatusType = Otter::Core::BaseComponents::WIN;
            Otter::Games::RType::System::GameServer::EndGameMessage::SendWin(ref);
        }
        InitWinScene(ref);
    }

    void CheckWin(Otter::Core::Orchestrator& ref)
    {
        auto& enemies = ref.get_components<Otter::Core::BaseComponents::Enemy>();
        std::size_t enemyCount = 0;

        for (std::size_t i = 0; i < enemies.size(); i++) {
            if (enemies[i])
                enemyCount++;
        }
        if (enemyCount == 0) {
            TriggerWin(ref);
        }
    }

    void HandleWin(Otter::Core::Orchestrator& ref, std::vector<std::size_t>&)
    {
        auto& eventNetworks = ref.get_components<Otter::Core::BaseComponents::EventNetwork>();

        std::cout << "Win" << std::endl;

        for (size_t i = 0; i < eventNetworks.size(); i++) {
            auto& eventNetwork = eventNetworks[i];

            if (!eventNetwork) {
                continue;
            }
        }
    }

} // namespace Otter::Games::RType::System::Win
