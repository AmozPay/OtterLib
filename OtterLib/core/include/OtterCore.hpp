#pragma once

#include "Orchestrator.hpp"
#include "SystemManager.hpp"

namespace Otter::Core {

    extern void registerComponents(Otter::Core::Orchestrator &);
    extern void registerSystems(Otter::Core::SystemManager &);

    class OtterCore {
      public:
        OtterCore() : _factory(), _data(_factory), _systems() { _isRunning = true; };

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
        Orchestrator _data;
        SystemManager _systems;
    };
} // namespace Otter::Core
