// #include "OtterGraphic.hpp"
// #include "OtterNetwork.hpp"

#include "Components.hpp"
#include "OtterCore.hpp"
#include "System.hpp"

namespace Otter::Core {

    void createEntityObj(Otter::Core::Orchestrator&) {}

    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<Otter::Games::RType::Components::Window>();
        ref.register_component<Otter::Games::RType::Components::Texture>();
        ref.register_component<Otter::Games::RType::Components::Render>();
        ref.register_component<Otter::Games::RType::Components::Keyboard>();
        ref.register_component<Otter::Games::RType::Components::Transform>();
        ref.register_component<Otter::Games::RType::Components::BoxCollider>();
        ref.register_component<Otter::Games::RType::Components::Health>();
        ref.register_component<Otter::Games::RType::Components::Player>();
        ref.register_component<Otter::Games::RType::Components::Velocity>();

// TODO: need to be cleaned
#if defined(TARGET_CLIENT)

        Entity e1 = ref.createEntity();
        ref.add_component(e1, Otter::Games::RType::Components::Window(1280, 720, "title", 60));

#endif
        
        Entity e = ref.createEntity();
        Entity e2 = ref.createEntity();

#if defined(TARGET_CLIENT)
        ref.add_component(e, Otter::Games::RType::Components::Texture(
                                 "../assets/image.png", Otter::Graphic::Raylib::RaylibTexture("../assets/image.png")));
        ref.add_component(e, Otter::Games::RType::Components::Render());
        ref.add_component(e, Otter::Games::RType::Components::Keyboard());
        
        ref.add_component(e2, Otter::Games::RType::Components::Texture(
                                  "../assets/image.png", Otter::Graphic::Raylib::RaylibTexture("../assets/image.png")));
        ref.add_component(e2, Otter::Games::RType::Components::Render());
        ref.add_component(e2, Otter::Games::RType::Components::Keyboard());
#endif

        ref.add_component(e, Otter::Games::RType::Components::Transform(0.05, 0, {200, 410}));
        ref.add_component(e, Otter::Games::RType::Components::Player(20, "test"));
        ref.add_component(e, Otter::Games::RType::Components::Velocity(10, {1, 1}));
        ref.add_component(e, Otter::Games::RType::Components::BoxCollider(200, 200));
        ref.add_component(e, Otter::Games::RType::Components::Health(100));
        
        ref.add_component(e2, Otter::Games::RType::Components::Transform(0.05, 0, {200, 200}));
        ref.add_component(e2, Otter::Games::RType::Components::Velocity(10, {1, 1}));
        ref.add_component(e2, Otter::Games::RType::Components::BoxCollider(200, 200));
        ref.add_component(e2, Otter::Games::RType::Components::Health(100));
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
#if defined(TARGET_CLIENT)
        ref.registerSystem(Otter::Games::RType::System::Window::SetTargetFPS, Otter::Core::SystemManager::init);
        ref.registerSystem(Otter::Games::RType::System::Event::PollEvent, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(Otter::Games::RType::System::Move::EntityMovement, Otter::Core::SystemManager::update);
        ref.registerSystem(Otter::Games::RType::System::Collision::EntityCollision, Otter::Core::SystemManager::update);
        ref.registerSystem(Otter::Games::RType::System::Window::BeginDraw, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(Otter::Games::RType::System::Window::ClearBackground, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(Otter::Games::RType::System::Sprite::Draw, Otter::Core::SystemManager::draw);
        ref.registerSystem(Otter::Games::RType::System::Window::EndDraw, Otter::Core::SystemManager::subDraw);
#elif defined(TARGET_SERVER)
        std::cout << "Server here" << std::endl;
#endif
    }
} // namespace Otter::Core
