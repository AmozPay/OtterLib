#pragma once

#include "windows_config.hpp"
#include "Orchestrator.hpp"
#include "ScriptingManager.hpp"
#include "SystemManager.hpp"

namespace Otter::Core {

    DllImport void registerComponents(Otter::Core::Orchestrator&);
    DllImport void registerSystems(Otter::Core::SystemManager&);
    DllImport void createEntityObj(Otter::Core::Orchestrator&);
    DllImport void configureScripting(Otter::Scripting::ScriptingManager&);

    class OtterCore {
      public:
        OtterCore() : _factory(), _systems(), _data(_factory), _scriptingManager(_systems, _data)
        {
            _isRunning = true;
        };

        ~OtterCore(){};

        /**
         * @brief start the engine
         * @return exit code
         */
        int engineStart();

      private:
        void loop();
        void init();
        void _registerBaseComponents(void);

        bool _isRunning;

        Factory _factory;
        SystemManager _systems;
        Orchestrator _data;
        Otter::Scripting::ScriptingManager _scriptingManager;
    };
} // namespace Otter::Core
