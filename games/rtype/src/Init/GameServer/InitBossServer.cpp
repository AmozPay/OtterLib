/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitBoss
*/

#include "InitBossServer.hpp"

namespace Otter::Games::GameServer::Init {
    InitBoss::InitBoss(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                    Otter::Games::RType::Utils::Vector2 pos)
    {
        Otter::Core::Entity boss = ref.createEntity();

        ref.add_component(boss, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(boss, Otter::Core::BaseComponents::Velocity(2, 2, {-1, 0}, {0, 0}));
        ref.add_component(boss, Otter::Core::BaseComponents::Enemy(25, id));
        ref.add_component(boss, Otter::Core::BaseComponents::BoxCollider(360, 150));
        ref.add_component(boss, Otter::Core::BaseComponents::Damage(25));
        ref.add_component(boss, Otter::Core::BaseComponents::Health(400));
    }

    InitBoss::~InitBoss() {}
}