/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameClient
*/

#include "OtterGraphic.hpp"
#include "baseComponents.hpp"
#include "GameClient.hpp"

namespace Otter::Games::GameClient {
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

        ref.add_component(baseEntity, Otter::Core::BaseComponents::Window(1280, 720, "title", 60));
        ref.add_component(
            baseEntity,
            Otter::Core::BaseComponents::TextureStorage(Otter::Core::BaseComponents::TextureStorageMap(
                {{"../assets/spaceship.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/spaceship.gif")},
                 {"../assets/obstacle.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/obstacle.gif")},
                 {"../assets/mobs.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/mobs.gif")},
                 {"../assets/background.png", Otter::Graphic::Raylib::RaylibTexture("../assets/background.png")},
                 {"../assets/projectile.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/projectile.gif")}})));

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        ref.add_component(player,
                          Otter::Core::BaseComponents::Texture("../assets/spaceship.gif",
                                              textureStorages[baseEntity]->findTextureByPath("../assets/spaceship.gif"),
                                              Otter::Games::RType::Utils::Rectangle(0, 0, 32, 14)));
        ref.add_component(player, Otter::Core::BaseComponents::Render());
        ref.add_component(player, Otter::Core::BaseComponents::Keyboard());
        ref.add_component(player, Otter::Core::BaseComponents::EventNetwork());

        ref.add_component(invisibleWall,
                          Otter::Core::BaseComponents::Texture("../assets/obstacle.gif",
                                              textureStorages[baseEntity]->findTextureByPath("../assets/obstacle.gif"),
                                              Otter::Games::RType::Utils::Rectangle(0, 0, 62, 24)));

        ref.add_component(obstacle,
                          Otter::Core::BaseComponents::Texture("../assets/obstacle.gif",
                                              textureStorages[baseEntity]->findTextureByPath("../assets/obstacle.gif"),
                                              Otter::Games::RType::Utils::Rectangle(0, 0, 62, 24)));
        ref.add_component(obstacle, Otter::Core::BaseComponents::Render());

        ref.add_component(mobs,
                          Otter::Core::BaseComponents::Texture("../assets/mobs.gif",
                                              textureStorages[baseEntity]->findTextureByPath("../assets/mobs.gif"),
                                              Otter::Games::RType::Utils::Rectangle(0, 0, 32, 29)));
        ref.add_component(mobs, Otter::Core::BaseComponents::Render());

        for (unsigned int& parallax : parallaxes) {
            ref.add_component(parallax, Otter::Core::BaseComponents::Texture(
                                            "../assets/background.png",
                                            textureStorages[baseEntity]->findTextureByPath("../assets/background.png"),
                                            Otter::Games::RType::Utils::Rectangle(0, 0, 1226, 207)));
            ref.add_component(parallax, Otter::Core::BaseComponents::Render());
            ref.add_component(parallax, Otter::Core::BaseComponents::Parallax());
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
            ref.add_component(parallaxes[i], Otter::Core::BaseComponents::Transform(1, 0, {static_cast<float>(i * 1226), 0}));
            ref.add_component(parallaxes[i], Otter::Core::BaseComponents::Velocity(0, 5, {-1, 0}, {0, 0}));
        }

        auto& keyboards = ref.get_components<Otter::Core::BaseComponents::Keyboard>();
        keyboards[player]->setKey(keyboards[player]->_keyboard.LEFT, utils::EventState::BACKWARD);
        keyboards[player]->setKey(keyboards[player]->_keyboard.RIGHT, utils::EventState::FORWARD);
        keyboards[player]->setKey(keyboards[player]->_keyboard.UP, utils::EventState::UP);
        keyboards[player]->setKey(keyboards[player]->_keyboard.DOWN, utils::EventState::DOWN);
        keyboards[player]->setKey(keyboards[player]->_keyboard.SHIFT, utils::EventState::SHOOT);
    }

    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<components::Obstacle>();
        ref.register_component<components::Shooter>();
        ref.register_component<components::Shot>();
        ref.register_component<components::EventHandlerComponent>();
        ref.register_component<components::EventComponent>();
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
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
    }
} // namespace Otter::Games::GameClient