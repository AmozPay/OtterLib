#pragma once

#include "Orchestrator.hpp"
#include "SystemManager.hpp"

namespace Otter::Core {

    class OtterCore {
      public:
        OtterCore() : _data(), _systems() { _isRunning = true; }

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
    };
} // namespace Otter::Core
