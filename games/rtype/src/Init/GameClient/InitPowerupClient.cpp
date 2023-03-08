/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitPowerup
*/

#include "InitPowerupClient.hpp"

namespace Otter::Games::GameClient::Init {
    InitPowerup::InitPowerup(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Core::Utils::Vector2 pos, Otter::Games::RType::Components::PowerupType powerupType, int powerupValue)
    {
        Otter::Core::Entity powerup = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        std::string paths[] = {"../assets/power-up-health-20x20.png", "../assets/power-up-damage-20x20.png", "../assets/power-up-speed-20x20.png", "../assets/power-up-slowness-20x20.png", "../assets/power-up-strength-20x20.png", "../assets/power-up-weakness-20x20.png"};

        // Powerup generation
        ref.add_component(powerup, Otter::Core::BaseComponents::Texture(
                                        paths[powerupType],
                                        textureStorages[baseEntity]->findTextureByPath(paths[powerupType]),
                                        Otter::Core::Utils::Rectangle(0, 0, 20, 20)));
        ref.add_component(powerup, Otter::Core::BaseComponents::Render());

        ref.add_component(powerup, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(powerup, Otter::Core::BaseComponents::Velocity(1.5, 2, {-1, 0}, {0, 0}));
        ref.add_component(powerup, Otter::Core::BaseComponents::BoxCollider(40, 40));

        ref.add_component(powerup, components::Powerup(powerupType, powerupValue));
        ref.add_component(powerup, components::Obstacle(components::ObstacleType::POWERUP, id));
    }

    InitPowerup::~InitPowerup() {}
} // namespace Otter::Games::GameClient::Init
