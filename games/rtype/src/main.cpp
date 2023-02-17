// #include "OtterGraphic.hpp"
// #include "OtterNetwork.hpp"

#include "Components.hpp"
#include "OtterCore.hpp"
#include "System.hpp"

namespace Otter::Core {
    namespace components = Otter::Games::RType::Components;
    namespace systems = Otter::Games::RType::System;
    namespace utils = Otter::Games::RType::Utils;

    void createEntityObj(Otter::Core::Orchestrator& ref)
    {
        // TODO: need to be cleaned
        Entity baseEntity = ref.createEntity();
        Entity player = ref.createEntity();
        Entity invisibleWall = ref.createEntity();
        Entity obstacle = ref.createEntity();
        Entity mobs = ref.createEntity();
        Entity parallaxes[2];
        for (unsigned int& parallax : parallaxes) {
            parallax = ref.createEntity();
        }

#if defined(TARGET_CLIENT)

        ref.add_component(baseEntity, components::Window(1280, 720, "title", 60));

        ref.add_component(player, components::Texture("../assets/spaceship.gif", Otter::Graphic::Raylib::RaylibTexture(
                                                                                     "../assets/spaceship.gif")));
        ref.add_component(player, components::Render());
        ref.add_component(player, components::Keyboard());
        ref.add_component(player, components::EventNetwork());

        ref.add_component(invisibleWall,
                          components::Texture("../assets/obstacle.gif",
                                              Otter::Graphic::Raylib::RaylibTexture("../assets/obstacle.gif")));

        ref.add_component(obstacle, components::Texture("../assets/obstacle.gif", Otter::Graphic::Raylib::RaylibTexture(
                                                                                      "../assets/obstacle.gif")));
        ref.add_component(obstacle, components::Render());

        ref.add_component(mobs, components::Texture("../assets/mobs.gif",
                                                    Otter::Graphic::Raylib::RaylibTexture("../assets/mobs.gif")));
        ref.add_component(mobs, components::Render());

        for (unsigned int& parallax : parallaxes) {
            ref.add_component(parallax,
                              components::Texture("../assets/background.png",
                                                  Otter::Graphic::Raylib::RaylibTexture("../assets/background.png")));
            ref.add_component(parallax, components::Render());
            ref.add_component(parallax, components::Parallax());
        }

#endif

        ref.add_component(baseEntity, components::EventComponent());
        ref.add_component(baseEntity, components::EventHandlerComponent(components::EventHandlerMap(
                                          {{components::EventTypes::COLISION, systems::Collision::HandleCollision},
                                           {components::EventTypes::DEATH, systems::Death::HandleDeath}})));

        ref.add_component(player, components::Transform(3, 0, {200, 200}));
        ref.add_component(player, components::Player(20, "test"));
        ref.add_component(player, components::Velocity(5, 0, {1, 10}, {1, 1}));
        ref.add_component(player, components::BoxCollider(96, 42));
        ref.add_component(player, components::Health(100));
        ref.add_component(player, components::Shooter(components::ShotDirection::RIGHT, true, -1, -1));

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

        for (int i = 0; i < 2; i++) {
            ref.add_component(parallaxes[i], components::Transform(1, 0, {static_cast<float>(i * 1226), 0}));
            ref.add_component(parallaxes[i], components::Velocity(0, 5, {-1, 0}, {0, 0}));
        }

#if defined(TARGET_CLIENT)
        auto& keyboards = ref.get_components<components::Keyboard>();
        keyboards[player]->setKey(keyboards[player]->_keyboard.LEFT, utils::EventState::BACKWARD);
        keyboards[player]->setKey(keyboards[player]->_keyboard.RIGHT, utils::EventState::FORWARD);
        keyboards[player]->setKey(keyboards[player]->_keyboard.UP, utils::EventState::UP);
        keyboards[player]->setKey(keyboards[player]->_keyboard.DOWN, utils::EventState::DOWN);
        keyboards[player]->setKey(keyboards[player]->_keyboard.SHIFT, utils::EventState::SHOOT);
#endif
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
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
#if defined(TARGET_CLIENT)
        ref.registerSystem(systems::Window::SetTargetFPS, Otter::Core::SystemManager::init);
        ref.registerSystem(systems::Window::WindowShouldClose, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(systems::Event::PollEvent, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(systems::EventNetwork::EventHandler, Otter::Core::SystemManager::event);
        ref.registerSystem(systems::Parallax::ParallaxHandler, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::Move::EntityMovement, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Collision::EntityCollision, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Death::EntityDeath, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::EventHandler::EventHandlerSystem, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Window::BeginDraw, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(systems::Window::ClearBackground, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(systems::Sprite::DrawParallax, Otter::Core::SystemManager::draw);
        ref.registerSystem(systems::Sprite::Draw, Otter::Core::SystemManager::draw);
        ref.registerSystem(systems::Window::EndDraw, Otter::Core::SystemManager::subDraw);
#elif defined(TARGET_SERVER)
        std::cout << "Server here" << std::endl;
#endif
    }
} // namespace Otter::Core
