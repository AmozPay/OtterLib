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

        Otter::Core::Entity enemy = ref.createEntity();
        ref.add_component(enemy, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Velocity(2, 2, {-1, 0}, {0, 0}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Enemy(25, id));
        ref.add_component(enemy, Otter::Core::BaseComponents::BoxCollider(34, 34));
        ref.add_component(enemy, Otter::Core::BaseComponents::Damage(20));
        ref.add_component(enemy, Otter::Core::BaseComponents::Health(10));
    }

    InitEnemy::~InitEnemy() {}
} // namespace Otter::Games::GameServer::Init
