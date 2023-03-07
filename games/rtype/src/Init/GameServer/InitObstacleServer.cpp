/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitObstacle
*/

#include "InitObstacleServer.hpp"

namespace Otter::Games::GameServer::Init {
    InitObstacle::InitObstacle(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Core::Entity obstacle = ref.createEntity();
        ref.add_component(obstacle, Otter::Core::BaseComponents::Transform(4, 0, {0, 0}));
        ref.add_component(obstacle, Otter::Core::BaseComponents::Velocity(0, 0, {0, 0}, {0, 0}));
        ref.add_component(obstacle, Otter::Core::BaseComponents::BoxCollider(248, 96));
        ref.add_component(obstacle, components::Obstacle(components::ObstacleType::WALL, "test"));
    }

    InitObstacle::~InitObstacle() {}
} // namespace Otter::Games::GameServer::Init
