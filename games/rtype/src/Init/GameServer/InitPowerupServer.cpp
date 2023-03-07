/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitPowerup
*/

#include "InitPowerupServer.hpp"

namespace Otter::Games::GameServer::Init {
    InitPowerup::InitPowerup(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Games::RType::Utils::Vector2 pos, Otter::Games::RType::Components::PowerupType powerupType, int powerupValue)
    {
        Otter::Core::Entity powerup = ref.createEntity();

        ref.add_component(powerup, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(powerup, Otter::Core::BaseComponents::Velocity(1.5, 2, {-1, 0}, {0, 0}));
        ref.add_component(powerup, Otter::Core::BaseComponents::BoxCollider(40, 40));

        ref.add_component(powerup, components::Powerup(powerupType, powerupValue));
        ref.add_component(powerup, components::Obstacle(components::ObstacleType::POWERUP, id));
    }

    InitPowerup::~InitPowerup() {}
} // namespace Otter::Games::GameClient::Init
