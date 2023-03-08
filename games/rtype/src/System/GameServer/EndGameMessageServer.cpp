/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** EndGameMessageServer
*/

#include "EndGameMessageServer.hpp"

namespace Otter::Games::RType::System::GameServer::EndGameMessage
{

    void InitGameOverScene(Otter::Core::Orchestrator& ref)
    {
        auto& players = ref.get_components<Otter::Core::BaseComponents::Player>();
        auto& enemies = ref.get_components<Otter::Core::BaseComponents::Enemy>();
        auto& velocities = ref.get_components<Otter::Core::BaseComponents::Velocity>();

        for (std::size_t i = 0; i < players.size() || i < enemies.size(); i++) {
            if (players[i]) {
                ref.remove_entity(static_cast<std::uint32_t>(i));
            }
            if (enemies[i] && velocities[i]) {
                ref.remove_component<Otter::Core::BaseComponents::Velocity>(static_cast<std::uint32_t>(i));
            }
        }
    }

    void TriggerGameOver(Otter::Core::Orchestrator& ref)
    {
        auto& gameStatus = ref.get_components<Otter::Core::BaseComponents::GameStatus>();

        for (std::size_t i = 0; i < gameStatus.size(); i++) {
            if (!gameStatus[i])
                continue;
            if (gameStatus[i]->gameStatusType != Otter::Core::BaseComponents::GAME)
                continue;
            gameStatus[i]->gameStatusType = Otter::Core::BaseComponents::GAME_OVER;
        }
        InitGameOverScene(ref);
    }

    void ReceiveGameOver(Otter::Core::Orchestrator& ref, std::string&, int)
    {
        TriggerGameOver(ref);
        SendGameOver(ref);
    }

    void SendGameOver(Otter::Core::Orchestrator& ref)
    {
        auto& servers = ref.get_components<Otter::Network::ServerComponent>();

        std::stringstream data;
        network::Sender::broadCast_msg(ref, network::GAME_OVER, data);
        std::cout << "Game sent !!" << std::endl;
    }

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
        }
        InitWinScene(ref);
    }

    void ReceiveWin(Otter::Core::Orchestrator& ref, std::string&, int)
    {
        TriggerWin(ref);
        SendWin(ref);
    }

    void SendWin(Otter::Core::Orchestrator& ref)
    {
        auto& servers = ref.get_components<Otter::Network::ServerComponent>();

        std::stringstream data;
        network::Sender::broadCast_msg(ref, network::WIN, data);
        std::cout << "Game sent !!" << std::endl;
    }
}