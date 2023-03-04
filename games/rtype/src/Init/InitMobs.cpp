/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitMobs
*/

#include "InitMobs.hpp"

namespace Otter::Games::GameClient::Init
{
    InitMobs::InitMobs(
        Otter::Core::Orchestrator& ref,
        Otter::Core::Entity baseEntity
    )
    {
        Otter::Core::Entity mobs = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        ref.add_component(mobs,
                          Otter::Core::BaseComponents::Texture("../assets/mobs.gif",
                                              textureStorages[baseEntity]->findTextureByPath("../assets/mobs.gif"),
                                              Otter::Games::RType::Utils::Rectangle(0, 0, 32, 29)));
        ref.add_component(mobs, Otter::Core::BaseComponents::Render());

        ref.add_component(mobs, Otter::Core::BaseComponents::Transform(2, 0, {800, 300}));
        ref.add_component(mobs, Otter::Core::BaseComponents::Velocity(0, 0, {0, 0}, {0, 0}));
        ref.add_component(mobs, Otter::Core::BaseComponents::Enemy(25, "test"));
        ref.add_component(mobs, Otter::Core::BaseComponents::BoxCollider(64, 58));
        ref.add_component(mobs, Otter::Core::BaseComponents::Damage(20));
        ref.add_component(mobs, Otter::Core::BaseComponents::Health(100));
    }

    InitMobs::~InitMobs()
    {

    }
}
