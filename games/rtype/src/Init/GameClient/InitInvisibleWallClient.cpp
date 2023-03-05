/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitInvisibleWall
*/

#include "InitInvisibleWallClient.hpp"

namespace Otter::Games::GameClient::Init
{
    InitInvisibleWall::InitInvisibleWall(
        Otter::Core::Orchestrator& ref,
        Otter::Core::Entity baseEntity
    )
    {
        Otter::Core::Entity invisibleWall = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();
        ref.add_component(invisibleWall,
                          Otter::Core::BaseComponents::Texture("../assets/obstacle.gif",
                                              textureStorages[baseEntity]->findTextureByPath("../assets/obstacle.gif"),
                                              Otter::Games::RType::Utils::Rectangle(0, 0, 62, 24)));

        ref.add_component(invisibleWall, Otter::Core::BaseComponents::BoxCollider(10, 720));
        ref.add_component(invisibleWall, Otter::Core::BaseComponents::Transform(1, 0, {-10, 0}));
        ref.add_component(invisibleWall, components::Obstacle(components::ObstacleType::WALL, "invisible_wall"));
    }

    InitInvisibleWall::~InitInvisibleWall()
    {

    }
}
