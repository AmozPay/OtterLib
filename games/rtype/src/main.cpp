// #include "OtterGraphic.hpp"
// #include "OtterNetwork.hpp"

#include "Components.hpp"
#include "OtterCore.hpp"
#include "System.hpp"

namespace Otter::Core {

    void createEntityObj(Otter::Core::Orchestrator& ref)
    {
// TODO: need to be cleaned
#if defined(TARGET_CLIENT)

        Entity e1 = ref.createEntity();
        ref.add_component(e1, Otter::Games::RType::Components::Window(1280, 720, "title", 60));

#endif

        Entity e = ref.createEntity();
        Entity parallaxes[2];
        for (unsigned int& parallax : parallaxes) {
            parallax = ref.createEntity();
        }
        Entity entities[12];
        for (unsigned int& entity : entities) {
            entity = ref.createEntity();
        }

#if defined(TARGET_CLIENT)
        ref.add_component(
            e, Otter::Games::RType::Components::Texture(
                   "../assets/spaceship.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/spaceship.gif")));
        ref.add_component(e, Otter::Games::RType::Components::Render());
        ref.add_component(e, Otter::Games::RType::Components::Keyboard());
        ref.add_component(e, Otter::Games::RType::Components::EventNetwork());
        for (unsigned int& entity : entities) {
            ref.add_component(
                entity, Otter::Games::RType::Components::Texture(
                            "../assets/obstacle.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/obstacle.gif")));
            ref.add_component(entity, Otter::Games::RType::Components::Render());
        }
        for (unsigned int& parallax : parallaxes) {
            ref.add_component(parallax, Otter::Games::RType::Components::Texture(
                                            "../assets/background.png",
                                            Otter::Graphic::Raylib::RaylibTexture("../assets/background.png")));
            ref.add_component(parallax, Otter::Games::RType::Components::Render());
            ref.add_component(parallax, Otter::Games::RType::Components::Parallax());
        }
#endif

        ref.add_component(e, Otter::Games::RType::Components::Transform(3, 0, {200, 200}));
        ref.add_component(e, Otter::Games::RType::Components::Player(20, "test"));
        ref.add_component(e, Otter::Games::RType::Components::Velocity(5, 0, {1, 1}, {1, 1}));
        ref.add_component(e, Otter::Games::RType::Components::BoxCollider(96, 42));
        ref.add_component(e, Otter::Games::RType::Components::Health(100));
        ref.add_component(e, Otter::Games::RType::Components::Shooter(
                                 Otter::Games::RType::Components::ShotDirection::RIGHT, true, -1, 0));

        for (int i = 0; i < 7; i++) {
            ref.add_component(entities[i],
                              Otter::Games::RType::Components::Transform(4, 0, {static_cast<float>(248 * i), 0}));
            ref.add_component(entities[i], Otter::Games::RType::Components::Velocity(0, 0, {0, 0}, {0, 0}));
            ref.add_component(entities[i], Otter::Games::RType::Components::BoxCollider(248, 96));
            ref.add_component(entities[i], Otter::Games::RType::Components::Obstacle(
                                               Otter::Games::RType::Components::ObstacleType::WALL, "test"));
        }
        for (int i = 0; i < 6; i++) {
            ref.add_component(entities[i + 6],
                              Otter::Games::RType::Components::Transform(4, 0, {static_cast<float>(248 * i), 624}));
            ref.add_component(entities[i + 6], Otter::Games::RType::Components::Velocity(0, 0, {0, 0}, {0, 0}));
            ref.add_component(entities[i + 6], Otter::Games::RType::Components::BoxCollider(248, 96));
            ref.add_component(entities[i + 6], Otter::Games::RType::Components::Obstacle(
                                                   Otter::Games::RType::Components::ObstacleType::WALL, "test"));
        }

        for (int i = 0; i < 2; i++) {
            ref.add_component(parallaxes[i],
                              Otter::Games::RType::Components::Transform(1, 0, {static_cast<float>(i * 1226), 0}));
            ref.add_component(parallaxes[i], Otter::Games::RType::Components::Velocity(0, 5, {-1, 0}, {0, 0}));
        }

        Entity invisibleWall = ref.createEntity();

        ref.add_component(invisibleWall, Otter::Games::RType::Components::BoxCollider(10, 720));
        ref.add_component(invisibleWall, Otter::Games::RType::Components::Transform(1, 0, {-10, 0}));

#if defined(TARGET_CLIENT)
        ref.add_component(invisibleWall, Otter::Games::RType::Components::Texture(
                                             "../assets/obstacle.gif",
                                             Otter::Graphic::Raylib::RaylibTexture("../assets/obstacle.gif")));

        auto& keyboards = ref.get_components<Otter::Games::RType::Components::Keyboard>();
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.LEFT, Otter::Games::RType::Utils::EventState::BACKWARD);
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.RIGHT, Otter::Games::RType::Utils::EventState::FORWARD);
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.UP, Otter::Games::RType::Utils::EventState::UP);
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.DOWN, Otter::Games::RType::Utils::EventState::DOWN);
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.SHIFT, Otter::Games::RType::Utils::EventState::SHOOT);
#endif
    }

    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<Otter::Games::RType::Components::Render>();
        ref.register_component<Otter::Games::RType::Components::Window>();
        ref.register_component<Otter::Games::RType::Components::Keyboard>();
        ref.register_component<Otter::Games::RType::Components::BoxCollider>();
        ref.register_component<Otter::Games::RType::Components::Sound>();
        ref.register_component<Otter::Games::RType::Components::Music>();
        ref.register_component<Otter::Games::RType::Components::Texture>();
        ref.register_component<Otter::Games::RType::Components::Transform>();
        ref.register_component<Otter::Games::RType::Components::Velocity>();
        ref.register_component<Otter::Games::RType::Components::Player>();
        ref.register_component<Otter::Games::RType::Components::Enemy>();
        ref.register_component<Otter::Games::RType::Components::Obstacle>();
        ref.register_component<Otter::Games::RType::Components::Health>();
        ref.register_component<Otter::Games::RType::Components::Damage>();
        ref.register_component<Otter::Games::RType::Components::Destructible>();
        ref.register_component<Otter::Games::RType::Components::Shooter>();
        ref.register_component<Otter::Games::RType::Components::Shot>();
        ref.register_component<Otter::Games::RType::Components::Dispawnable>();
        ref.register_component<Otter::Games::RType::Components::Parallax>();
        ref.register_component<Otter::Games::RType::Components::EventNetwork>();
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
#if defined(TARGET_CLIENT)
        ref.registerSystem(Otter::Games::RType::System::Window::SetTargetFPS, Otter::Core::SystemManager::init);
        ref.registerSystem(Otter::Games::RType::System::Window::WindowShouldClose,
                           Otter::Core::SystemManager::preEvent);
        ref.registerSystem(Otter::Games::RType::System::Event::PollEvent, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(Otter::Games::RType::System::EventNetwork::EventHandler, Otter::Core::SystemManager::event);
        ref.registerSystem(Otter::Games::RType::System::Parallax::ParallaxHandler,
                           Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(Otter::Games::RType::System::Move::EntityMovement, Otter::Core::SystemManager::update);
        ref.registerSystem(Otter::Games::RType::System::Collision::EntityCollision, Otter::Core::SystemManager::update);
        ref.registerSystem(Otter::Games::RType::System::Window::BeginDraw, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(Otter::Games::RType::System::Window::ClearBackground, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(Otter::Games::RType::System::Sprite::DrawParallax, Otter::Core::SystemManager::draw);
        ref.registerSystem(Otter::Games::RType::System::Sprite::Draw, Otter::Core::SystemManager::draw);
        ref.registerSystem(Otter::Games::RType::System::Window::EndDraw, Otter::Core::SystemManager::subDraw);
#elif defined(TARGET_SERVER)
        std::cout << "Server here" << std::endl;
#endif
    }
} // namespace Otter::Core
