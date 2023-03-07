/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitEnemy
*/

#include "InitEnemyServer.hpp"

namespace Otter::Games::GameServer::Init {
    InitEnemy::InitEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                         Otter::Games::RType::Utils::Vector2 pos)
    {
        // srand(42);
        int enemyType = rand() % 2;

        if (enemyType == 1)
            InitBasicEnemy(ref, baseEntity, id, pos);
        else
            InitShootingEnemy(ref, baseEntity, id, pos);
    }

    void InitEnemy::InitShootingEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                         Otter::Games::RType::Utils::Vector2 pos)
    {
        Otter::Core::Entity enemy = ref.createEntity();

        ref.add_component(enemy, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Velocity(2, 2, {-1, 0}, {0, 0}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Enemy(25, id));
        ref.add_component(enemy, Otter::Core::BaseComponents::BoxCollider(68, 68));
        ref.add_component(enemy, Otter::Core::BaseComponents::Damage(10));
        ref.add_component(enemy, Otter::Core::BaseComponents::Health(10));

        ref.add_component(enemy, components::Shooter(components::ShotDirection::LEFT, true, -1, 2000));
    }

    void InitEnemy::InitBasicEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                         Otter::Games::RType::Utils::Vector2 pos)
    {
        Otter::Core::Entity enemy = ref.createEntity();

        ref.add_component(enemy, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Velocity(2, 2, {-1, 0}, {0, 0}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Enemy(25, id));
        ref.add_component(enemy, Otter::Core::BaseComponents::BoxCollider(58, 44));
        ref.add_component(enemy, Otter::Core::BaseComponents::Damage(10));
        ref.add_component(enemy, Otter::Core::BaseComponents::Health(20));
    }

    InitEnemy::~InitEnemy() {}
} // namespace Otter::Games::GameServer::Init
