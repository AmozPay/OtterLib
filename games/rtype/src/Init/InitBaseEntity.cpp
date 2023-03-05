/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitBaseEntity
*/

#include "InitBaseEntity.hpp"

namespace Otter::Games::GameClient::Init
{
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
                 {"../assets/enemy1-34x34.png", Otter::Graphic::Raylib::RaylibTexture("../assets/enemy1-34x34.png")},
                 {"../assets/r-typesheet43.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/r-typesheet43.gif")},
                 {"../assets/parallax-1920x1080.png", Otter::Graphic::Raylib::RaylibTexture("../assets/parallax-1920x1080.png")}})));
        ref.add_component(baseEntity, components::EventComponent());
        ref.add_component(baseEntity, components::EventHandlerComponent(
            components::EventHandlerMap(
                {
                    {components::EventTypes::COLISION, systems::Collision::HandleCollision},
                    {components::EventTypes::DEATH, systems::Death::HandleDeath},
                    {components::EventTypes::LOBBY, systems::Lobby::HandleLobby},
                    {components::EventTypes::INIT_GAME, systems::InitGame::HandleInitGame},
                    {components::EventTypes::GAME_OVER, systems::GameOver::HandleGameOver},
                    {components::EventTypes::WIN, systems::Win::HandleWin}
                }
            )));
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

    InitBaseEntity::~InitBaseEntity()
    {

    }

    Otter::Core::Entity InitBaseEntity::getEntity() const
    {
        return baseEntity;
    }


}
