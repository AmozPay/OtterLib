#include "OtterCore.hpp"
#include "System.hpp"

void func(Otter::Core::Orchestrator& ref) { std::cout << "i am working" << std::endl; }

void func1(Otter::Core::Orchestrator& ref) { std::cout << "i am working2" << std::endl; }

void func2(Otter::Core::Orchestrator& ref) { std::cout << "i am working3" << std::endl; }

namespace Otter::Core {

    void OtterCore::registerComponents()
    {
        _data.register_component<test_str>();
        _data.register_component<testcomponent>();
    }

    void OtterCore::registerSystems()
    {
        _systems.registerSystem(func, Otter::Core::SystemManager::init);
        _systems.registerSystem(func1, Otter::Core::SystemManager::update);
        _systems.registerSystem(func2, Otter::Core::SystemManager::preUpdate);

        _systems.registerSystem(Otter::Games::RType::System::Sprite::Load, Otter::Core::SystemManager::init);
        _systems.registerSystem(Otter::Games::RType::System::Sprite::Draw, Otter::Core::SystemManager::draw);
    }

} // namespace Otter::Core
