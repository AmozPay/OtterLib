/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** MovePlayerMessage
*/

#include "MovePlayerMessageClient.hpp"

namespace Otter::Games::RType::System::GameClient::MovePlayerMessage
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

    void movePlayer(
        Otter::Core::Orchestrator& ref,
        int &playerId,
        utils::Vector2 pos
    ) {
        std::size_t playerIndex = getPlayerById(ref, playerId);
        auto &players = ref.get_components<baseComponent::Transform>();

        if (playerIndex >= players.size())
            return;

        if (!players[playerIndex])
            return;
        players[playerIndex]->_position = pos;
    }


    void ReceiveMovePlayerMessage(Otter::Core::Orchestrator& ref, std::string& data, int)
    {
        try
        {
            int playerId = network::Deserializer::loadArchiveFromString<int>(data);
            int x = network::Deserializer::loadArchiveFromString<utils::EventState>(data);
            int y = network::Deserializer::loadArchiveFromString<utils::EventState>(data);


            movePlayer(
                ref,
                playerId,
                utils::Vector2(x, y)
            );

            std::cout << "Player position updated !!" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    

    void SendMovePlayerMessage(
        Otter::Core::Orchestrator& ref,
        std::size_t &playerId,
        utils::EventState &state
    )
    {
        auto& servers = ref.get_components<Otter::Network::ServerComponent>();
        auto& players = ref.get_components<baseComponent::Player>();

        std::size_t test = players.size();

        if (players.size() <= playerId)
            return;

        if (!players[playerId])
            return;

        std::stringstream data;

        network::Serializer::saveArchive(data, players[playerId]->_id);
        network::Serializer::saveArchive(data, state);

        system::GameClient::SendMessageToServer::Send(ref, network::PLAYER_MOVE, data);

        std::cout << "Move player sent !!" << std::endl;
    }
}