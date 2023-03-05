#pragma once

#include "SystemManager.hpp"
#include "lua_wrapper.hpp"

namespace Otter::Scripting {

    // This is not inteded to be used by lua developpers, but is used to retrieve
    // user created scripts and call them in the proper phase. This is called by a library available system.
    static const std::string luaCallScripts = "\
        function __callScripts(phase)\n\
            for k, v in pairs(OtterLib.systems.phasesEnum[phase]) do\n\
                v()\n\
            end\n\
        end\n\
    ";

    static const std::string isGraphicsEnabledLuaFmt = "\
        function __isGraphicEnabled()\n\
            return %1%\
        end\n\
    ";

    /**
     * @brief ScriptingManager is responsible for :
     * 1 - managing the lua context
     * 2 - creating and registring lua objects available to developper scripts
     * 3 - loading developper scripts and components
     * It therefore needs access to the system manager (to add scriting handler systems), and the orchestrator (to give
     * access to the orchestrator to scripts)
     */
    class ScriptingManager {
      public:
        ScriptingManager(Otter::Core::SystemManager& systemManager, Otter::Core::Orchestrator& orchestrator)
            : _luaContext(), _systemManager(systemManager), _orchestrator(orchestrator), _graphicsEnabled(false)
        {
        }

        ~ScriptingManager() = default;
        void enableScripting(const std::string scriptingEntrypointDirectory);
        void enableGraphics(void);

      private:
        void setupComponentBindings(void);
        LuaContext _luaContext;
        Otter::Core::SystemManager& _systemManager;
        Otter::Core::Orchestrator& _orchestrator;
        bool _graphicsEnabled;
    };
} // namespace Otter::Scripting