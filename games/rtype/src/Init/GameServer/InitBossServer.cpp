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
        ref.add_component(boss, Otter::Core::BaseComponents::Enemy(25, "boss"));
        ref.add_component(boss, Otter::Core::BaseComponents::BoxCollider(360, 300));
        ref.add_component(boss, Otter::Core::BaseComponents::Damage(25));
        ref.add_component(boss, Otter::Core::BaseComponents::Health(200));
        ref.add_component(boss, Otter::Games::RType::Components::Deceleration(1280, 0.004));
        ref.add_component(boss, Otter::Games::RType::Components::Hovering(1, 50, 550, Otter::Games::RType::Components::HoveringDirection::DOWN));

        ref.add_component(boss, components::Shooter(components::ShotDirection::LEFT, true, -1, 1000));
    }

    InitBoss::~InitBoss() {}
}