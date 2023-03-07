/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitGameSystem
*/

#include "InitGameSystemClient.hpp"

#include "InitEnemyClient.hpp"
#include "InitInvisibleWallClient.hpp"
#include "InitMobsClient.hpp"
#include "InitObstacleClient.hpp"
#include "InitParallaxesClient.hpp"
#include "InitPlayerClient.hpp"

namespace Otter::Games::RType::System::GameClient::InitGame {

    void InitGame(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Games::GameClient::Init::InitParallaxes parallaxes(ref, baseEntity);
        Otter::Games::GameClient::Init::InitInvisibleWall invisibleWall(ref, baseEntity);
        Otter::Games::GameClient::Init::InitPlayer player(ref, baseEntity);

        srand(42);
        int enmiesMaxNb = 20;
        int enemyMaxPos = enmiesMaxNb * 300;
        int range = 21 - 1;
        int num = 0;
        for (int i = 0; i < enmiesMaxNb; i++) {
            enemyMaxPos = enemyMaxPos - 300;
            num = rand() % range;
            Otter::Games::GameClient::Init::InitEnemy enemy(
                ref, baseEntity, i,
                Otter::Games::RType::Utils::Vector2(8000 + enemyMaxPos, 34 * num));
        }
    }

    void HandleInitGame(Otter::Core::Orchestrator& ref, std::vector<std::size_t>&)
    {
        auto& gameStatuses = ref.get_components<Otter::Core::BaseComponents::GameStatus>();

        for (std::size_t i = 0; i < gameStatuses.size(); i++) {
            if (!gameStatuses[i]) {
                continue;
            }

            InitGame(ref, static_cast<Otter::Core::Entity>(i));
            gameStatuses[i]->gameStatusType = Otter::Core::BaseComponents::GAME;
            return;
        }
    }
} // namespace Otter::Games::RType::System::GameClient::InitGame
