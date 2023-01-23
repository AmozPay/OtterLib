#include "OtterCore.hpp"

void func(Otter::Core::Orchestrator& ref) { std::cout << "i am working" << std::endl; }

namespace Otter::Core {

    void OtterCore::registerComponents() {}

    void OtterCore::registerSystems() { _systems.registerSystem(func); }
} // namespace Otter::Core
