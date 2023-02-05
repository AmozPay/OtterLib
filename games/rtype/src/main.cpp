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
        ref.register_component<Otter::Games::RType::Components::Player>();
        ref.register_component<Otter::Games::RType::Components::Velocity>();

// TODO: need to be cleaned
#if defined(TARGET_CLIENT)

        Entity e1 = ref.createEntity();
        ref.add_component(e1, Otter::Games::RType::Components::Window(1280, 720, "title", 60));
#endif

        Entity e = ref.createEntity();

#if defined(TARGET_CLIENT)
        ref.add_component(e, Otter::Games::RType::Components::Texture(
                                 "../assets/spaceship.gif", Otter::Graphic::Raylib::RaylibTexture("../assets/spaceship.gif")));
        ref.add_component(e, Otter::Games::RType::Components::Render());
        ref.add_component(e, Otter::Games::RType::Components::Keyboard());
#endif

        ref.add_component(e, Otter::Games::RType::Components::Transform(0.1, 0, {200, 200}));
        ref.add_component(e, Otter::Games::RType::Components::Player(20, "test"));
        ref.add_component(e, Otter::Games::RType::Components::Velocity(5, {1, 1}));
        auto& keyboards = ref.get_components<Otter::Games::RType::Components::Keyboard>();
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.LEFT, Otter::Games::RType::Utils::EventState::BACKWARD);
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.RIGHT, Otter::Games::RType::Utils::EventState::FORWARD);
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.UP, Otter::Games::RType::Utils::EventState::UP);
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.DOWN, Otter::Games::RType::Utils::EventState::DOWN);
        keyboards[e]->_keyboard.setKey(keyboards[e]->_keyboard.ESCAPE, Otter::Games::RType::Utils::EventState::CLOSE);
    }

    void registerSystems(Otter::Core::SystemManager& ref)
    {
#if defined(TARGET_CLIENT)
        ref.registerSystem(Otter::Games::RType::System::Window::SetTargetFPS, Otter::Core::SystemManager::init);
        ref.registerSystem(Otter::Games::RType::System::Event::PollEvent, Otter::Core::SystemManager::preEvent);
        ref.registerSystem(Otter::Games::RType::System::Move::EntityMovement, Otter::Core::SystemManager::update);
        ref.registerSystem(Otter::Games::RType::System::Window::BeginDraw, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(Otter::Games::RType::System::Window::ClearBackground, Otter::Core::SystemManager::preDraw);
        ref.registerSystem(Otter::Games::RType::System::Sprite::Draw, Otter::Core::SystemManager::draw);
        ref.registerSystem(Otter::Games::RType::System::Window::EndDraw, Otter::Core::SystemManager::subDraw);
#elif defined(TARGET_SERVER)
        std::cout << "Server here" << std::endl;
#endif
    }
} // namespace Otter::Core
