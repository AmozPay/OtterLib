/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameServer
*/

#include "GameServer.hpp"

namespace Otter::Games::GameServer {
    void createEntityObj(Otter::Core::Orchestrator& ref)
    {
        // TODO: need to be cleaned
        Otter::Core::Entity baseEntity = ref.createEntity();
        Otter::Core::Entity player = ref.createEntity();
        Otter::Core::Entity invisibleWall = ref.createEntity();
        Otter::Core::Entity obstacle = ref.createEntity();
        Otter::Core::Entity mobs = ref.createEntity();
        Otter::Core::Entity parallaxes[2];

        for (unsigned int& parallax : parallaxes) {
            parallax = ref.createEntity();
        }

        ref.add_component(baseEntity, components::EventComponent());
        ref.add_component(baseEntity, components::EventHandlerComponent(components::EventHandlerMap(
                                          {{components::EventTypes::COLISION, systems::Collision::HandleCollision},
                                           {components::EventTypes::DEATH, systems::Death::HandleDeath}})));

        ref.add_component(player, components::Transform(3, 0, {200, 200}));
        ref.add_component(player, components::Player(20, "test"));
        ref.add_component(player, components::Velocity(5, 0, {1, 10}, {1, 1}));
        ref.add_component(player, components::BoxCollider(96, 42));
        ref.add_component(player, components::Health(100));
        ref.add_component(player, components::Shooter(components::ShotDirection::RIGHT, true, -1, 0.001));
        ref.add_component(player, components::Damage(10));

        ref.add_component(invisibleWall, components::BoxCollider(10, 720));
        ref.add_component(invisibleWall, components::Transform(1, 0, {-10, 0}));
        ref.add_component(invisibleWall, components::Obstacle(components::ObstacleType::WALL, "invisible_wall"));

        ref.add_component(obstacle, components::Transform(4, 0, {0, 0}));
        ref.add_component(obstacle, components::Velocity(0, 0, {0, 0}, {0, 0}));
        ref.add_component(obstacle, components::BoxCollider(248, 96));
        ref.add_component(obstacle, components::Obstacle(components::ObstacleType::WALL, "test"));

        ref.add_component(mobs, components::Transform(2, 0, {800, 300}));
        ref.add_component(mobs, components::Velocity(0, 0, {0, 0}, {0, 0}));
        ref.add_component(mobs, components::Enemy(25, "test"));
        ref.add_component(mobs, components::BoxCollider(64, 58));
        ref.add_component(mobs, components::Damage(20));
        ref.add_component(mobs, components::Health(100));

        for (int i = 0; i < 2; i++) {
            ref.add_component(parallaxes[i], components::Transform(1, 0, {static_cast<float>(i * 1226), 0}));
            ref.add_component(parallaxes[i], components::Velocity(0, 5, {-1, 0}, {0, 0}));
        }
    }

    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<components::Render>();
        ref.register_component<components::Window>();
        ref.register_component<components::Keyboard>();
        ref.register_component<components::BoxCollider>();
        ref.register_component<components::Sound>();
        ref.register_component<components::Music>();
        ref.register_component<components::Texture>();
        ref.register_component<components::Transform>();
        ref.register_component<components::Velocity>();
        ref.register_component<components::Player>();
        ref.register_component<components::Enemy>();
        ref.register_component<components::Obstacle>();
        ref.register_component<components::Health>();
        ref.register_component<components::Damage>();
        ref.register_component<components::Destructible>();
        ref.register_component<components::Shooter>();
        ref.register_component<components::Shot>();
        ref.register_component<components::Dispawnable>();
        ref.register_component<components::Parallax>();
        ref.register_component<components::EventNetwork>();
        ref.register_component<components::EventHandlerComponent>();
        ref.register_component<components::EventComponent>();
        ref.register_component<components::TextureStorage>();
    }

    void registerSystems(Otter::Core::SystemManager& ref) { std::cout << "Server here" << std::endl; }
} // namespace Otter::Games::GameServer
