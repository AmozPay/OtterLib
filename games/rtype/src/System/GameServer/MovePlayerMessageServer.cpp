/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** MovePlayerMessage
*/

#include "MovePlayerMessageServer.hpp"

namespace Otter::Games::RType::System::GameServer::MovePlayerMessage
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
        utils::EventState &state
    ) {
        std::size_t playerIndex = getPlayerById(ref, playerId);
        auto& velocities = ref.get_components<baseComponent::Velocity>();

        if (playerIndex <= velocities.size() && velocities[playerIndex]) {
            auto& velocity = velocities[playerIndex];
            if (state == utils::EventState::BACKWARD) {
                velocity->_accelerationDirection.x += -1;
            }
            if (state == utils::EventState::FORWARD) {
                velocity->_accelerationDirection.x += 1;
            }
            if (state == utils::EventState::UP) {
                velocity->_accelerationDirection.y += -1;
            }
            if (state == utils::EventState::DOWN) {
                velocity->_accelerationDirection.y += 1;
            }
        }   
    }


    void ReceiveMovePlayerMessage(Otter::Core::Orchestrator& ref, std::string& data, int)
    {
        try
        {
            int playerId = network::Deserializer::loadArchiveFromString<int>(data);
            utils::EventState eventstate = network::Deserializer::loadArchiveFromString<utils::EventState>(data);

            movePlayer(ref, playerId, eventstate);
            std::cout << "Player moved !!" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void SendMovePlayerMessage(
        Otter::Core::Orchestrator& ref,
        int &playerId,
        utils::Vector2 &pos
    )
    {
        std::stringstream data;

        network::Serializer::saveArchive(data, playerId);
        network::Serializer::saveArchive(data, pos.x);
        network::Serializer::saveArchive(data, pos.y);
        network::Sender::broadCast_msg(ref, network::PLAYER_MOVE, data);
        std::cout << "Player position sent !!" << std::endl;
    }
}