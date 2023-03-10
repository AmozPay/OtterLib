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
#include "InitBossClient.hpp"
#include "InitPowerupClient.hpp"

namespace Otter::Games::RType::System::GameClient::InitGame {

    namespace componets = Otter::Games::RType::Components;

    void CreatePowerup(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        int powerupValue[] = {25, 15, 5, 2, 2, 1};

        srand(42);
        int powerupMaxNb = 10;
        int powerupMaxPos = powerupMaxNb * 800;
        int range = 21 - 1;
        int num = 0;
        int powerupType = 0;
        for (int i = 0; i < powerupMaxNb; i++) {
            powerupMaxPos = powerupMaxPos - 800;
            num = rand() % range;
            powerupType = rand() % 5;
            Otter::Games::GameClient::Init::InitPowerup powerup(
                ref, baseEntity, "Enemy " + std::to_string(i),
                Otter::Core::Utils::Vector2(1280 + powerupMaxPos, 34 * num), static_cast<components::PowerupType>(powerupType), powerupValue[powerupType]);
        }
    }

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
                ref, baseEntity, "Enemy " + std::to_string(i),
                Otter::Core::Utils::Vector2(800 + enemyMaxPos, 34 * num + 30));
        }
        Otter::Games::GameClient::Init::InitBoss boss(ref, baseEntity, "Boss 1",
                Otter::Core::Utils::Vector2(enmiesMaxNb * 300 + 1000, 150));

        CreatePowerup(ref, baseEntity);
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
