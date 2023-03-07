/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** MovePlayerMessage
*/

#include "MoveEnemyMessageServer.hpp"

namespace Otter::Games::RType::System::GameServer::MoveEnemyMessage
{
    void SendMoveEnemyMessage(
        Otter::Core::Orchestrator& ref,
        int &enemyId,
        utils::Vector2 &pos
    )
    {
        std::stringstream data;

        network::Serializer::saveArchive(data, enemyId);
        network::Serializer::saveArchive(data, pos.x);
        network::Serializer::saveArchive(data, pos.y);
        network::Sender::broadCast_msg(ref, network::ENEMY_MOVE, data);
        std::cout << "Enemy position sent !!" << std::endl;
    }
}