#pragma once

#include "lua_wrapper.hpp"
#include "SystemManager.hpp"

namespace Otter::Scripting {

    static const std::string luaSystemsTable = "\
        OtterSystems = {\
            init = {},\
            preEvent = {},\
            event = {},\
            preUpdate = {},\
            update = {},\
            preDraw = {},\
            draw = {},\
            subDraw = {},\
            [\"end\"] = {}\
        }\
    ";

    static const std::string luaCallScripts = "\
        function __callScripts(phase)\n\
            for k, v in pairs(OtterSystems[phase]) do\n\
                v()\n\
            end\n\
        end\n\
    ";

    class ScriptingManager {
        public:
            ScriptingManager(Otter::Core::SystemManager &systemManager): _luaContext(), _systemManager(systemManager) {}
            ~ScriptingManager() = default;
            void enableScripting(const std::string scriptingEntrypointFile);
        private:
            LuaContext _luaContext;
            Otter::Core::SystemManager &_systemManager;
    };
}