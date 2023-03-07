/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** MovePlayerMessage
*/

#include "MoveEnemyMessageClient.hpp"

namespace Otter::Games::RType::System::GameClient::MoveEnemyMessage
{
    std::size_t getEnemyById(
        Otter::Core::Orchestrator& ref,
        int &enemyId
    ) {
        auto &enemies = ref.get_components<baseComponent::Enemy>();

        for (std::size_t i = 0; i < enemies.size(); i++)
        {
            if (!enemies[i])
                continue;

            if (enemies[i]->_id == enemyId)
                return i;
        }

        return 0;
    }

    void moveEnemy(
        Otter::Core::Orchestrator& ref,
        int &enemyId,
        utils::Vector2 pos
    ) {
        std::size_t playerIndex = getEnemyById(ref, enemyId);
        auto &players = ref.get_components<baseComponent::Transform>();

        if (playerIndex >= players.size())
            return;

        if (!players[playerIndex])
            return;
        players[playerIndex]->_position = pos;
    }


    void ReceiveMoveEnemyMessage(Otter::Core::Orchestrator& ref, std::string& data, int)
    {
        try
        {
            int enemyId = network::Deserializer::loadArchiveFromString<int>(data);
            int x = network::Deserializer::loadArchiveFromString<utils::EventState>(data);
            int y = network::Deserializer::loadArchiveFromString<utils::EventState>(data);

            moveEnemy(
                ref,
                enemyId,
                utils::Vector2(x, y)
            );

            std::cout << "Enemy position updated !!" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}