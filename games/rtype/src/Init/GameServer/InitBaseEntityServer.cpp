/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitBaseEntity
*/

#include "InitBaseEntityServer.hpp"

namespace Otter::Games::GameServer::Init {
    InitBaseEntity::InitBaseEntity(Otter::Core::Orchestrator& ref)
    {
        // TODO: need to be cleaned
        baseEntity = ref.createEntity();

        std::cout << "base entity loaded" << std::endl;

        ref.add_component(baseEntity, components::EventComponent());
        ref.add_component(baseEntity,
                          components::EventHandlerComponent(components::EventHandlerMap(
                              {{components::EventTypes::COLISION, systems::Collision::HandleCollision},
                               {components::EventTypes::DEATH, systems::Death::HandleDeathServer},
                               {components::EventTypes::LOBBY, systems::Lobby::HandleLobby},
                               {components::EventTypes::INIT_GAME, systems::GameServer::InitGame::HandleInitGame},
                               {components::EventTypes::GAME_OVER, systems::GameServer::GameOver::HandleGameOver},
                               {components::EventTypes::WIN, systems::GameServer::Win::HandleWin}})));
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

} // namespace Otter::Games::GameServer::Init
