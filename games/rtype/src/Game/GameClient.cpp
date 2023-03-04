/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameClient
*/

#include "GameClient.hpp"
#include <utility>

namespace Otter::Games::GameClient {
    void createEntityObj(Otter::Core::Orchestrator& ref)
    {
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
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
        ref.registerSystem(systems::Window::SetTargetFPS, Otter::Core::SystemManager::init);
        ref.registerSystem(systems::Window::WindowShouldClose, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(systems::Event::PollEvent, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(systems::Parallax::ParallaxHandler, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::GameStatus::HandleGameStatus, Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(systems::EventNetwork::EventHandler, Otter::Core::SystemManager::event);
        ref.registerSystem(systems::EventHandler::EventHandlerSystem, Otter::Core::SystemManager::event);
        ref.registerSystem(systems::Death::EntityDeath, Otter::Core::SystemManager::event);
        ref.registerSystem(systems::Move::EntityMovement, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Collision::EntityCollision, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Animation::animate, Otter::Core::SystemManager::update);
        ref.registerSystem(systems::Window::BeginDraw, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(systems::Window::ClearBackground, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(systems::Sprite::DrawParallax, Otter::Core::SystemManager::draw);
        ref.registerSystem(systems::Sprite::Draw, Otter::Core::SystemManager::draw);
        ref.registerSystem(systems::Window::EndDraw, Otter::Core::SystemManager::subDraw);
    }
} // namespace Otter::Games::GameClient