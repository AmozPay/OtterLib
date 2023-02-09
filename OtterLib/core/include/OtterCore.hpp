#pragma once

#include "Orchestrator.hpp"
#include "SystemManager.hpp"
#include "ScriptingManager.hpp"

namespace Otter::Core {

    extern void registerComponents(Otter::Core::Orchestrator&);
    extern void registerSystems(Otter::Core::SystemManager&);
    extern void createEntityObj(Otter::Core::Orchestrator&);

    class OtterCore {
      public:
        OtterCore() : _factory(), _systems(), _scriptingManager(_systems), _data(_factory) { _isRunning = true; };

        ~OtterCore(){};

        /**
         * @brief start the engine
         * @return exit code
         */
        int engineStart();

      private:
        void loop();
        void init();

        bool _isRunning;

        Factory _factory;
        SystemManager _systems;
        Otter::Scripting::ScriptingManager _scriptingManager;
        Orchestrator _data;
    };
} // namespace Otter::Core
