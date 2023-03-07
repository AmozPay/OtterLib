/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitGameSystem
*/

#include "InitGameSystemServer.hpp"

#include "InitEnemyServer.hpp"
#include "InitInvisibleWallServer.hpp"
#include "InitMobsServer.hpp"
#include "InitObstacleServer.hpp"
#include "InitParallaxesServer.hpp"
#include "InitPlayerServer.hpp"
#include "InitBossServer.hpp"

namespace Otter::Games::RType::System::GameServer::InitGame {

    void InitGame(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Games::GameServer::Init::InitParallaxes parallaxes(ref, baseEntity);
        Otter::Games::GameServer::Init::InitInvisibleWall invisibleWall(ref, baseEntity);
        Otter::Games::GameServer::Init::InitPlayer player(ref, baseEntity);

        srand(42);
        int enmiesMaxNb = 20;
        int enemyMaxPos = enmiesMaxNb * 300;
        int range = 21 - 1;
        int num = 0;
        for (int i = 0; i < enmiesMaxNb; i++) {
            enemyMaxPos = enemyMaxPos - 300;
            num = rand() % range;
            Otter::Games::GameServer::Init::InitEnemy enemy(
                ref, baseEntity, "Enemy " + std::to_string(i),
                Otter::Games::RType::Utils::Vector2(800 + enemyMaxPos, 34 * num + 30));
        }
        Otter::Games::GameServer::Init::InitBoss boss(ref, baseEntity, "Boss 1",
                Otter::Games::RType::Utils::Vector2(enmiesMaxNb * 300 + 1000, 150));
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
} // namespace Otter::Games::RType::System::GameServer::InitGame
