/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameServer
*/

#include "GameServer.hpp"
#include "OtterCore.hpp"
#include "baseComponents.hpp"

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

        ref.add_component(player, Otter::Core::BaseComponents::Transform(3, 0, {200, 200}));
        ref.add_component(player, Otter::Core::BaseComponents::Player(20, "test"));
        ref.add_component(player, Otter::Core::BaseComponents::Velocity(5, 0, {1, 10}, {1, 1}));
        ref.add_component(player, Otter::Core::BaseComponents::BoxCollider(96, 42));
        ref.add_component(player, Otter::Core::BaseComponents::Health(100));
        ref.add_component(player, components::Shooter(components::ShotDirection::RIGHT, true, -1, 0.001));
        ref.add_component(player, Otter::Core::BaseComponents::Damage(10));

        ref.add_component(invisibleWall, Otter::Core::BaseComponents::BoxCollider(10, 720));
        ref.add_component(invisibleWall, Otter::Core::BaseComponents::Transform(1, 0, {-10, 0}));
        ref.add_component(invisibleWall, components::Obstacle(components::ObstacleType::WALL, "invisible_wall"));

        ref.add_component(obstacle, Otter::Core::BaseComponents::Transform(4, 0, {0, 0}));
        ref.add_component(obstacle, Otter::Core::BaseComponents::Velocity(0, 0, {0, 0}, {0, 0}));
        ref.add_component(obstacle, Otter::Core::BaseComponents::BoxCollider(248, 96));
        ref.add_component(obstacle, components::Obstacle(components::ObstacleType::WALL, "test"));

        ref.add_component(mobs, Otter::Core::BaseComponents::Transform(2, 0, {800, 300}));
        ref.add_component(mobs, Otter::Core::BaseComponents::Velocity(0, 0, {0, 0}, {0, 0}));
        ref.add_component(mobs, Otter::Core::BaseComponents::Enemy(25, "test"));
        ref.add_component(mobs, Otter::Core::BaseComponents::BoxCollider(64, 58));
        ref.add_component(mobs, Otter::Core::BaseComponents::Damage(20));
        ref.add_component(mobs, Otter::Core::BaseComponents::Health(100));

        for (int i = 0; i < 2; i++) {
            ref.add_component(parallaxes[i],
                              Otter::Core::BaseComponents::Transform(1, 0, {static_cast<float>(i * 1226), 0}));
            ref.add_component(parallaxes[i], Otter::Core::BaseComponents::Velocity(0, 5, {-1, 0}, {0, 0}));
        }
    }

    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<components::Obstacle>();
        ref.register_component<components::Shooter>();
        ref.register_component<components::Shot>();
        ref.register_component<components::EventHandlerComponent>();
        ref.register_component<components::EventComponent>();
    }

    void registerSystems(Otter::Core::SystemManager& ref) { std::cout << "Server here" << std::endl; }

    void configureScripting(Otter::Scripting::ScriptingManager& scriptingManager)
    {
        scriptingManager.enableScripting("../scripts");
    }
} // namespace Otter::Games::GameServer
