/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitBoss
*/

#include "InitBossClient.hpp"

namespace Otter::Games::GameClient::Init {
    InitBoss::InitBoss(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                    Otter::Games::RType::Utils::Vector2 pos)
    {
        Otter::Core::Entity boss = ref.createEntity();
        Otter::Core::Entity bossHealth = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();
        ref.add_component(boss, Otter::Core::BaseComponents::Texture(
                                     "../assets/boss2-180x150.png",
                                     textureStorages[baseEntity]->findTextureByPath("../assets/boss2-180x150.png"),
                                     Otter::Games::RType::Utils::Rectangle(0, 0, 180, 150)));
        ref.add_component(boss, Otter::Core::BaseComponents::Render());
        ref.add_component(boss, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(boss, Otter::Core::BaseComponents::Velocity(2, 2, {-1, 0}, {0, 0}));
        ref.add_component(boss, Otter::Core::BaseComponents::Enemy(25, id));
        ref.add_component(boss, Otter::Core::BaseComponents::BoxCollider(360, 150));
        ref.add_component(boss, Otter::Core::BaseComponents::Damage(25));
        ref.add_component(boss, Otter::Core::BaseComponents::Health(400));
        
        // Boss health text
        ref.add_component(bossHealth, Otter::Core::BaseComponents::Text("", 24, "health", boss));
        ref.add_component(bossHealth, Otter::Core::BaseComponents::Transform(1, 0, {0, 0}));
    }

    InitBoss::~InitBoss() {}
}