/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitObstacle
*/

#include "InitObstacle.hpp"

namespace Otter::Games::GameClient::Init {
    InitObstacle::InitObstacle(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Core::Entity obstacle = ref.createEntity();
        Otter::Core::Entity powerup = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        // Powerup generation
        ref.add_component(powerup, Otter::Core::BaseComponents::Texture(
                                        "../assets/obstacle.gif",
                                        textureStorages[baseEntity]->findTextureByPath("../assets/obstacle.gif"),
                                        Otter::Games::RType::Utils::Rectangle(0, 0, 62, 24)));
        ref.add_component(powerup, Otter::Core::BaseComponents::Render());

        ref.add_component(powerup, components::Powerup(components::DAMAGE, 25));
        ref.add_component(powerup, Otter::Core::BaseComponents::Transform(1, 0, {600, 300}));
        ref.add_component(powerup, Otter::Core::BaseComponents::BoxCollider(62, 24));
        ref.add_component(powerup, components::Obstacle(components::ObstacleType::POWERUP, "health_powerup"));
    }

    InitObstacle::~InitObstacle() {}
} // namespace Otter::Games::GameClient::Init
