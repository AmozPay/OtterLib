/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** ShootMessageClient
*/

#include "ShootMessageClient.hpp"

namespace Otter::Games::RType::System::GameClient::ShootMessageClient
{

    std::size_t getPlayerById(Otter::Core::Orchestrator& ref, int &playerId)
    {
        auto &players = ref.get_components<baseComponent::Player>();

        for (std::size_t i = 0; i < players.size(); i++)
        {
            if (!players[i])
                continue;

            if (players[i]->_id == playerId)
                return i;
        }

        return 0;
    }

    void ReceiveShootMessage(Otter::Core::Orchestrator& ref, std::string& data, int)
    {
        try
        {

            int playerId = network::Deserializer::loadArchiveFromString<int>(data);
            std::size_t playerIndex = getPlayerById(ref, playerId);

            system::InputKeyEventSystem::CreateShot(ref, playerIndex);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
                 
    }

    void SendShootMessage(
        Otter::Core::Orchestrator& ref,
        std::size_t &playerIndex
    ) {
        auto& servers = ref.get_components<Otter::Network::ServerComponent>();
        auto& players = ref.get_components<baseComponent::Player>();

        std::size_t test = players.size();

        if (players.size() <= playerIndex)
            return;

        if (!players[playerIndex])
            return;

        std::stringstream data;

        network::Serializer::saveArchive(data, players[playerIndex]->_id);
        system::GameClient::SendMessageToServer::Send(ref, network::SHOOT, data);
        std::cout << "Shoot sent !!" << std::endl; 
    }
}
