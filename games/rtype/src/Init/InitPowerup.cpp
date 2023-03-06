/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitPowerup
*/

#include "InitPowerup.hpp"

namespace Otter::Games::GameClient::Init {
    InitPowerup::InitPowerup(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Games::RType::Utils::Vector2 pos, Otter::Games::RType::Components::PowerupType powerupType, int powerupValue)
    {
        Otter::Core::Entity powerup = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        // Powerup generation
        ref.add_component(powerup, Otter::Core::BaseComponents::Texture(
                                        "../assets/obstacle.gif",
                                        textureStorages[baseEntity]->findTextureByPath("../assets/obstacle.gif"),
                                        Otter::Games::RType::Utils::Rectangle(0, 0, 62, 24)));
        ref.add_component(powerup, Otter::Core::BaseComponents::Render());

        ref.add_component(powerup, Otter::Core::BaseComponents::Transform(1, 0, {pos.x, pos.y}));
        ref.add_component(powerup, Otter::Core::BaseComponents::Velocity(1.5, 2, {-1, 0}, {0, 0}));
        ref.add_component(powerup, Otter::Core::BaseComponents::BoxCollider(62, 24));

        ref.add_component(powerup, components::Powerup(powerupType, powerupValue));
        ref.add_component(powerup, components::Obstacle(components::ObstacleType::POWERUP, id));
    }

    InitPowerup::~InitPowerup() {}
} // namespace Otter::Games::GameClient::Init
