/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitMobs
*/

#include "InitMobsServer.hpp"

namespace Otter::Games::GameServer::Init {
    InitMobs::InitMobs(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Core::Entity mobs = ref.createEntity();

        ref.add_component(mobs, Otter::Core::BaseComponents::Transform(2, 0, {800, 300}));
        ref.add_component(mobs, Otter::Core::BaseComponents::Velocity(0, 0, {0, 0}, {0, 0}));
        ref.add_component(mobs, Otter::Core::BaseComponents::Enemy(25, "test"));
        ref.add_component(mobs, Otter::Core::BaseComponents::BoxCollider(64, 58));
        ref.add_component(mobs, Otter::Core::BaseComponents::Damage(20));
        ref.add_component(mobs, Otter::Core::BaseComponents::Health(100));
    }

    InitMobs::~InitMobs() {}
} // namespace Otter::Games::GameServer::Init
