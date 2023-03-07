/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitObstacle
*/

#include "InitObstacleClient.hpp"

namespace Otter::Games::GameClient::Init {
    InitObstacle::InitObstacle(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Core::Entity obstacle = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        ref.add_component(obstacle, Otter::Core::BaseComponents::Texture(
                                        "../assets/obstacle.gif",
                                        textureStorages[baseEntity]->findTextureByPath("../assets/obstacle.gif"),
                                        Otter::Games::RType::Utils::Rectangle(0, 0, 62, 24)));
        ref.add_component(obstacle, Otter::Core::BaseComponents::Render());

        ref.add_component(obstacle, Otter::Core::BaseComponents::Transform(4, 0, {0, 0}));
        ref.add_component(obstacle, Otter::Core::BaseComponents::Velocity(0, 0, {0, 0}, {0, 0}));
        ref.add_component(obstacle, Otter::Core::BaseComponents::BoxCollider(248, 96));
        ref.add_component(obstacle, components::Obstacle(components::ObstacleType::WALL, "test"));
    }

    InitObstacle::~InitObstacle() {}
} // namespace Otter::Games::GameClient::Init
