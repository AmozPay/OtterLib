/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameOverSystem
*/

#include "GameOverSystem.hpp"

namespace Otter::Games::RType::System::GameOver
{
    void InitGameOverScene(Otter::Core::Orchestrator& ref)
    {
        auto &players = ref.get_components<Otter::Core::BaseComponents::Player>();
        auto &enemies = ref.get_components<Otter::Core::BaseComponents::Enemy>();
        auto &velocities = ref.get_components<Otter::Core::BaseComponents::Velocity>();

        for (std::size_t i = 0; i < players.size() || i < enemies.size(); i++) {
            if (players[i]) {
                ref.remove_entity(static_cast<std::uint32_t>(i));
            }
            if (enemies[i] && velocities[i]) {
                ref.remove_component<Otter::Core::BaseComponents::Velocity>(
                    static_cast<std::uint32_t>(i)
                );
            }
        }
    }

    void TriggerGameOver(
        Otter::Core::Orchestrator& ref
    )
    {
        auto &gameStatus = ref.get_components<Otter::Core::BaseComponents::GameStatus>();

        for (std::size_t i = 0; i < gameStatus.size(); i++) {
            if (!gameStatus[i])
                continue;
            if (gameStatus[i]->gameStatusType != Otter::Core::BaseComponents::GAME)
                continue;
            gameStatus[i]->gameStatusType = Otter::Core::BaseComponents::GAME_OVER;
        }
        InitGameOverScene(ref);
    }

    void CheckGameOver(Otter::Core::Orchestrator& ref)
    {
        auto &players = ref.get_components<Otter::Core::BaseComponents::Player>();
        std::size_t enemyCount = 0;

        for (std::size_t i = 0; i < players.size(); i++) {
            if (players[i])
                enemyCount++;
        }
        if (enemyCount == 0)
            TriggerGameOver(ref);

    }

    void HandleGameOver(
        Otter::Core::Orchestrator& ref,
        std::vector<std::size_t>&
    )
    {
        auto &eventNetworks = ref.get_components<Otter::Core::BaseComponents::EventNetwork>();

        for (size_t i = 0; i < eventNetworks.size(); i++) {
            auto& eventNetwork = eventNetworks[i];

            if (!eventNetwork) {
                continue;
            }
        }
    }
}