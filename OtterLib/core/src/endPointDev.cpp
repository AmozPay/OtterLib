#include "OtterCore.hpp"

void func(Otter::Core::Orchestrator& ref) { std::cout << "i am working" << std::endl; }

namespace Otter::Core {

    void OtterCore::registerComponents()
    {
        _data.register_component<test_str>();
        _data.register_component<testcomponent>();
    }

    void OtterCore::registerSystems() {}
} // namespace Otter::Core
