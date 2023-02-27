#pragma once

#include "lua_wrapper.hpp"
#include "SystemManager.hpp"

namespace Otter::Scripting {

    // // Here, we're creating lua code that is directly embeded in the program executable.
    // // This is later added to a lua context so that lua developpers can access these objects in their scripts
    // static const std::string luaSystemsTable = "\
    //     OtterLib = {\
    //         systems = {\
    //             init = {},\
    //             preEvent = {},\
    //             event = {},\
    //             preUpdate = {},\
    //             update = {},\
    //             preDraw = {},\
    //             draw = {},\
    //             subDraw = {},\
    //             [\"end\"] = {}\
    //         }\
    //     }\
    // ";

    // This is not inteded to be used by lua developpers, but is used to retrieve
    // user created scripts and call them in the proper phase. This is called by a library available system.
    static const std::string luaCallScripts = "\
        function __callScripts(phase)\n\
            for k, v in pairs(OtterLib.systems[phase]) do\n\
                v()\n\
            end\n\
        end\n\
    ";

    /**
     * @brief ScriptingManager is responsible for :
     * 1 - managing the lua context
     * 2 - creating and registring lua objects available to developper scripts
     * 3 - loading developper scripts and components
     * It therefore needs access to the system manager (to add scriting handler systems), and the orchestrator (to give access to the orchestrator to scripts)
     */
    class ScriptingManager {
        public:
            ScriptingManager(Otter::Core::SystemManager &systemManager, Otter::Core::Orchestrator &orchestrator): _luaContext(), _systemManager(systemManager), _orchestrator(orchestrator) {}
            ~ScriptingManager() = default;
            void enableScripting(const std::string scriptingEntrypointDirectory);
        private:
            LuaContext _luaContext;
            Otter::Core::SystemManager &_systemManager;
            Otter::Core::Orchestrator &_orchestrator;
    };
}