/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitBaseEntity
*/

#include "InitBaseEntityClient.hpp"

namespace Otter::Games::GameClient::Init {
    InitBaseEntity::InitBaseEntity(Otter::Core::Orchestrator& ref)
    {
        // TODO: need to be cleaned
        baseEntity = ref.createEntity();

        ref.add_component(baseEntity, Otter::Core::BaseComponents::Window(1280, 720, "title", 60));
        ref.add_component(
            baseEntity,
            Otter::Core::BaseComponents::TextureStorage(Otter::Core::BaseComponents::TextureStorageMap(
                {{"../assets/spaceship.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/spaceship.gif")},
                 {"../assets/obstacle.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/obstacle.gif")},
                 {"../assets/mobs.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/mobs.gif")},
                 {"../assets/background.png", Otter::Graphic::Raylib::RaylibTexture("../assets/background.png")},
                 {"../assets/projectile.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/projectile.gif")},
                 {"../assets/ennemyShoot2-16x16.png", Otter::Graphic::Raylib::RaylibTexture("../assets/ennemyShoot2-16x16.png")},
                 {"../assets/enemy1-34x34.png", Otter::Graphic::Raylib::RaylibTexture("../assets/enemy1-34x34.png")},
                 {"../assets/enemy2-29x22.png", Otter::Graphic::Raylib::RaylibTexture("../assets/enemy2-29x22.png")},
                 {"../assets/r-typesheet43.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/r-typesheet43.gif")},
                 {"../assets/parallax-1920x1080.png", Otter::Graphic::Raylib::RaylibTexture("../assets/parallax-1920x1080.png")},
                 {"../assets/power-up-damage-20x20.png", Otter::Graphic::Raylib::RaylibTexture("../assets/power-up-damage-20x20.png")},
                 {"../assets/power-up-health-20x20.png", Otter::Graphic::Raylib::RaylibTexture("../assets/power-up-health-20x20.png")},
                 {"../assets/power-up-slowness-20x20.png", Otter::Graphic::Raylib::RaylibTexture("../assets/power-up-slowness-20x20.png")},
                 {"../assets/power-up-speed-20x20.png", Otter::Graphic::Raylib::RaylibTexture("../assets/power-up-speed-20x20.png")},
                 {"../assets/power-up-strength-20x20.png", Otter::Graphic::Raylib::RaylibTexture("../assets/power-up-strength-20x20.png")},
                 {"../assets/power-up-weakness-20x20.png", Otter::Graphic::Raylib::RaylibTexture("../assets/power-up-weakness-20x20.png")}})));
        ref.add_component(baseEntity, components::EventComponent());
        ref.add_component(baseEntity,
                          components::EventHandlerComponent(components::EventHandlerMap(
                              {{components::EventTypes::COLISION, systems::Collision::HandleCollision},
                               {components::EventTypes::DEATH, systems::Death::HandleDeathClient},
                               {components::EventTypes::LOBBY, systems::Lobby::HandleLobby},
                               {components::EventTypes::INIT_GAME, systems::GameClient::InitGame::HandleInitGame},
                               {components::EventTypes::GAME_OVER, systems::GameOver::HandleGameOver},
                               {components::EventTypes::WIN, systems::Win::HandleWin}})));
        ref.add_component(baseEntity, Otter::Core::BaseComponents::Keyboard());
        ref.add_component(baseEntity, Otter::Core::BaseComponents::EventNetwork());
        ref.add_component(baseEntity, Otter::Core::BaseComponents::GameStatus(Otter::Core::BaseComponents::LOBBY));

        auto& keyboards = ref.get_components<Otter::Core::BaseComponents::Keyboard>();
        keyboards[baseEntity]->setKey(keyboards[baseEntity]->_keyboard.LEFT, utils::EventState::BACKWARD);
        keyboards[baseEntity]->setKey(keyboards[baseEntity]->_keyboard.RIGHT, utils::EventState::FORWARD);
        keyboards[baseEntity]->setKey(keyboards[baseEntity]->_keyboard.UP, utils::EventState::UP);
        keyboards[baseEntity]->setKey(keyboards[baseEntity]->_keyboard.DOWN, utils::EventState::DOWN);
        keyboards[baseEntity]->setKey(keyboards[baseEntity]->_keyboard.SHIFT, utils::EventState::SHOOT);
    }

    InitBaseEntity::~InitBaseEntity() {}

    Otter::Core::Entity InitBaseEntity::getEntity() const { return baseEntity; }

} // namespace Otter::Games::GameClient::Init
