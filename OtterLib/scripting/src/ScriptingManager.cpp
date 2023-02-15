#include "ScriptingManager.hpp"


#define REGISTER_SYSTEM(phase) _systemManager.registerSystem([callScripts](Otter::Core::Orchestrator &o){callScripts(#phase);}, Otter::Core::SystemManager::phase)

namespace Otter::Scripting {
    // static const std::string getTableLenght

    void ScriptingManager::enableScripting(std::string scriptingEntrypointFile)
    {
        _luaContext.doString(luaSystemsTable);
        _luaContext.doFile(scriptingEntrypointFile);
        _luaContext.doString(luaCallScripts);
        std::cout << "[OtterLib] Scripts loaded" << std::endl;

        _luaContext.setGlobal("__orchestrator", &_orchestrator);


        auto callScripts = _luaContext.bind<char const *>("__callScripts", "", "s");
        _systemManager.registerSystem(std::function([callScripts](Otter::Core::Orchestrator &o){std::cout << "silenzio bruno" << std::endl;  callScripts("init");}), Otter::Core::SystemManager::init);

	  //REGISTER_SYSTEM(init);
        // REGISTER_SYSTEM(preEvent);
        // REGISTER_SYSTEM(event);
        // REGISTER_SYSTEM(preUpdate);
        // REGISTER_SYSTEM(update);
        // REGISTER_SYSTEM(preDraw);
        // REGISTER_SYSTEM(draw);
        // REGISTER_SYSTEM(subDraw);
        // REGISTER_SYSTEM(end);

        std::cout << "[OtterLib] Scripting initialized" << std::endl;
    }
} // namespace Otter::Scripting
