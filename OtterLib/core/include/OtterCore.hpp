#pragma once

#include "Factory.hpp"
#include "Orchestrator.hpp"
#include "SystemManager.hpp"

namespace Otter::Core {

    class OtterCore {
      public:
        OtterCore() : _data(), _systems(), _factory(_data) { _isRunning = true; }

        /**
         * @brief start the engine
         * @return exit code
         */
        int engineStart();
        void registerComponents();
        void registerSystems();

      private:
        void loop();
        void init();

        bool _isRunning;
        Orchestrator _data;
        SystemManager _systems;
        Factory _factory;
    };
} // namespace Otter::Core
