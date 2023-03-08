/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameServer
*/

#include "GameServer.hpp"

#include "ClientComponent.hpp"
#include "InputKeyEventSystem.hpp"
#include "NetworkComponent.hpp"
#include "Server.hpp"
#include "ServerComponent.hpp"
#include "MovePlayerMessageServer.hpp"
#include "MoveSystemServer.hpp"
#include "ShootMessageServer.hpp"
#include "EndGameMessageServer.hpp"
#include "lobbyComponent.hpp"
#include "InitGameMessageServer.hpp"

namespace Otter::Games::GameServer {
    void test_upd(Otter::Core::Orchestrator& ref)
    {
        auto& sock = ref.get_components<Otter::Network::SocketComponent>();
        auto& serv = ref.get_components<Otter::Network::ServerComponent>();

        for (int i = 0; i < sock.size(); i++) {
            if (!sock[i]) {
                continue;
            }
            std::cout << sock[i]->channel << std::endl;
            if (serv[i])
                std::cout << "serv exist with socket" << std::endl;
            else
                std::cout << "serv doest exist" << std::endl;
        }
    }

    void createEntityObj(Otter::Core::Orchestrator& ref)
    {
        Otter::Network::ServerComponent serverComponent;

        ref.builder.createFromFile("../entities/server_socket.json", ref, 0);

        auto &servers = ref.get_components<Otter::Network::ServerComponent>();
        servers[0]->callBack.push_back([](Otter::Core::Orchestrator&, std::string&, int) {});
        servers[0]->callBack.push_back([](Otter::Core::Orchestrator&, std::string&, int) {});
        servers[0]->callBack.push_back(systems::GameServer::InitGameMessage::HandleInitGame);
        servers[0]->callBack.push_back(systems::GameServer::MovePlayerMessage::ReceiveMovePlayerMessage);
        servers[0]->callBack.push_back([](Otter::Core::Orchestrator&, std::string&, int) {});
        servers[0]->callBack.push_back(systems::GameServer::ShootMessageServer::ReceiveShootMessage);
        servers[0]->callBack.push_back(systems::GameServer::EndGameMessage::ReceiveGameOver);
        servers[0]->callBack.push_back(systems::GameServer::EndGameMessage::ReceiveWin);


	serv[0]->mandatory_static.push_back(Otter::Network::MsgCode::INIT_GAME);

	ref.add_component(0, Otter::Games::RType::Components::lobbyComponent());
	Init::InitBaseEntity baseEntity(ref);

    }

    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<components::Obstacle>();
        ref.register_component<components::Shooter>();
        ref.register_component<components::Shot>();
        ref.register_component<components::EventHandlerComponent>();
        ref.register_component<components::EventComponent>();
        ref.register_component<Otter::Core::BaseComponents::TextureStorage>();
        ref.register_component<components::AnimationComponent>();

        ref.register_component<Otter::Network::SocketComponent>();
        ref.register_component<Otter::Network::ServerComponent>();
        ref.register_component<Otter::Network::ClientComponent>();
	ref.register_component<Otter::Games::RType::Components::lobbyComponent>();
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
        ref.registerSystem(Otter::Network::Server::init, Otter::Core::SystemManager::init);
        ref.registerSystem(systems::Event::PollEvent, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(Otter::Network::Server::update, Otter::Core::SystemManager::event);
        ref.registerSystem(systems::InputKeyEventSystem::EventHandler, Otter::Core::SystemManager::event);
        ref.registerSystem(systems::EventHandler::EventHandlerSystem, Otter::Core::SystemManager::event);
        ref.registerSystem(systems::Parallax::ParallaxHandler, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::GameStatus::HandleGameStatus, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::GameServer::Win::CheckWin, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::GameServer::GameOver::CheckGameOver, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::GameServer::Move::EntityMovement, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Collision::EntityCollision, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Death::EntityDeath, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::CheckClientNb::CheckClientNb, Otter::Core::SystemManager::update);

        ref.registerSystem(&test_upd, Otter::Core::SystemManager::init);
    }

    void configureScripting(Otter::Scripting::ScriptingManager& scriptingManager)
    {
        scriptingManager.enableScripting("../scripts");
    }
} // namespace Otter::Games::GameServer
