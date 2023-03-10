/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameClient
*/

#include "GameClient.hpp"

#include "Client.hpp"
#include "ClientComponent.hpp"
#include "GameClient.hpp"
#include "GameStatusSystem.hpp"
#include "InitGameMessage.hpp"
#include "NetworkComponent.hpp"
#include "OtterGraphic.hpp"
#include "Server.hpp"
#include "ServerComponent.hpp"
#include "baseComponents.hpp"

#include <utility>

namespace Otter::Games::GameClient {
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

        serverComponent.callBack.push_back([](Otter::Core::Orchestrator&, std::string&, int) {});
        serverComponent.callBack.push_back(systems::GameClient::InitGameMessage::HandleInitGameMessage);

        ref.add_component(0, Otter::Network::SocketComponent());
        ref.add_component(0, std::move(serverComponent));
        Init::InitBaseEntity baseEntity(ref);
    }

    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<components::Obstacle>();
        ref.register_component<components::Shooter>();
        ref.register_component<components::Shot>();
        ref.register_component<components::Menu>();
        ref.register_component<components::EventHandlerComponent>();
        ref.register_component<components::EventComponent>();
        ref.register_component<Otter::Core::BaseComponents::TextureStorage>();
        ref.register_component<components::AnimationComponent>();
        ref.register_component<components::Deceleration>();
        ref.register_component<components::Hovering>();
        ref.register_component<components::Powerup>();

        ref.register_component<Otter::Network::SocketComponent>();
        ref.register_component<Otter::Network::ServerComponent>();
        ref.register_component<Otter::Network::ClientComponent>();
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
        ref.registerSystem(Otter::Network::Client::init, Otter::Core::SystemManager::init);
        ref.registerSystem(systems::Window::SetTargetFPS, Otter::Core::SystemManager::init);
        ref.registerSystem(systems::Window::WindowShouldClose, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(systems::Event::PollEvent, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(systems::Parallax::ParallaxHandler, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::GameStatus::HandleGameStatus, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::Win::CheckWin, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::GameOver::CheckGameOver, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::InputKeyEventSystem::EventHandler, Otter::Core::SystemManager::event);
        ref.registerSystem(systems::EventHandler::EventHandlerSystem, Otter::Core::SystemManager::event);
        ref.registerSystem(Otter::Network::Client::update, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::EnemyShot::AutomaticShotForEntity, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Deceleration::Deceleration, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Hovering::Hovering, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Move::EntityMovement, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Collision::EntityCollision, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Death::EntityDeath, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Text::UpdateHealthText, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Animation::animate, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Window::BeginDraw, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(systems::Window::ClearBackground, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(systems::Sprite::DrawParallax, Otter::Core::SystemManager::draw);
        ref.registerSystem(systems::Sprite::Draw, Otter::Core::SystemManager::draw);
        ref.registerSystem(systems::Text::DrawText, Otter::Core::SystemManager::draw);
        ref.registerSystem(systems::Window::EndDraw, Otter::Core::SystemManager::subDraw);

        ref.registerSystem(&test_upd, Otter::Core::SystemManager::init);
    }

    void configureScripting(Otter::Scripting::ScriptingManager& scriptingManager)
    {
        scriptingManager.enableScripting("../scripts");
        scriptingManager.enableGraphics();
    }
} // namespace Otter::Games::GameClient
