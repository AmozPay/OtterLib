/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameServer
*/

#include "GameServer.hpp"
#include "NetworkComponent.hpp"
#include "ServerComponent.hpp"
#include "ClientComponent.hpp"
#include "Server.hpp"
#include "InputKeyEventSystem.hpp"


namespace Otter::Games::GameServer {
     void test_upd(Otter::Core::Orchestrator &ref)
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
            std::cout << "serv doest exist" <<std::endl;
        
        }
    }


    void createEntityObj(Otter::Core::Orchestrator& ref)
    {
        ref.add_component(0, Otter::Network::SocketComponent());
        ref.add_component(0, Otter::Network::ServerComponent());
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
        ref.registerSystem(systems::Win::CheckWin, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::GameOver::CheckGameOver, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::Move::EntityMovement, Otter::Core::SystemManager::update);
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
