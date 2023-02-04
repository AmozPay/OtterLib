// #include "OtterGraphic.hpp"
// #include "OtterNetwork.hpp"

#include "Components.hpp"
#include "OtterCore.hpp"
#include "System.hpp"

namespace Otter::Core {
    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<Otter::Games::RType::Components::Window>();
        ref.register_component<Otter::Games::RType::Components::Texture>();
        ref.register_component<Otter::Games::RType::Components::Render>();
        ref.register_component<Otter::Games::RType::Components::Transform>();
        ref.register_component<Otter::Games::RType::Components::Keyboard>();
        ref.register_component<Otter::Games::RType::Components::Player>();
        ref.register_component<Otter::Games::RType::Components::Velocity>();
        ref.register_component<Otter::Games::RType::Components::Dispawnable>();

        // TODO: need to be cleaned
        Entity window = ref.createEntity();
        ref.add_component(window, Otter::Games::RType::Components::Window(1280, 720, "title", 60));

        Entity player = ref.createEntity();
        ref.add_component(player,
                          Otter::Games::RType::Components::Texture(
                              "../assets/image.png", Otter::Graphic::Raylib::RaylibTexture("../assets/image.png")));
        ref.add_component(player, Otter::Games::RType::Components::Render());
        ref.add_component(player, Otter::Games::RType::Components::Transform(0.1, 0, {200, 200}));
        ref.add_component(player, Otter::Games::RType::Components::Keyboard());
        ref.add_component(player, Otter::Games::RType::Components::Player(20, "test"));
        ref.add_component(player, Otter::Games::RType::Components::Dispawnable());
        ref.add_component(player, Otter::Games::RType::Components::Velocity(10, 1, {1, 0}, {1, 1}));
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
        ref.registerSystem(Otter::Games::RType::System::Window::SetTargetFPS, Otter::Core::SystemManager::init);
        ref.registerSystem(Otter::Games::RType::System::Event::PollEvent, Otter::Core::SystemManager::preEvent);
        // TODO: This system is not working
        //        ref.registerSystem(Otter::Games::RType::System::Dispawnable::EntityDispawn,
        //        Otter::Core::SystemManager::preUpdate);
        ref.registerSystem(Otter::Games::RType::System::Move::EntityMovement, Otter::Core::SystemManager::update);
        ref.registerSystem(Otter::Games::RType::System::Window::BeginDraw, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(Otter::Games::RType::System::Window::ClearBackground, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(Otter::Games::RType::System::Sprite::Draw, Otter::Core::SystemManager::draw);
        ref.registerSystem(Otter::Games::RType::System::Window::EndDraw, Otter::Core::SystemManager::subDraw);
    }
} // namespace Otter::Core