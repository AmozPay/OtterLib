/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** EndGameMessageClient
*/

#include "EndGameMessageClient.hpp"
#include "GameOverSystemClient.hpp"
#include "WinSystemClient.hpp"

namespace Otter::Games::RType::System::GameClient::EndGameMessage
{
    void ReceiveGameOver(Otter::Core::Orchestrator& ref, std::string&, int)
    {
        system::GameClient::GameOver::TriggerGameOver(ref);
    }

    void SendGameOver(Otter::Core::Orchestrator& ref)
    {
        auto& servers = ref.get_components<Otter::Network::ServerComponent>();

        std::stringstream data;
        system::GameClient::SendMessageToServer::Send(ref, network::GAME_OVER, data);
        std::cout << "Game sent !!" << std::endl;
    }

    void ReceiveWin(Otter::Core::Orchestrator& ref, std::string&, int)
    {
        system::GameClient::Win::TriggerWin(ref);   
    }

    void SendWin(Otter::Core::Orchestrator& ref)
    {
        auto& servers = ref.get_components<Otter::Network::ServerComponent>();

        std::stringstream data;
        system::GameClient::SendMessageToServer::Send(ref, network::WIN, data);
        std::cout << "Game sent !!" << std::endl;
    }      
}