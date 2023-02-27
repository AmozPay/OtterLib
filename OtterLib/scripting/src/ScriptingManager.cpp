#include "ScriptingManager.hpp"
#include "C2LuaBindings.hpp"

#define REGISTER_SYSTEM(phase)                                                                                         \
    _systemManager.registerSystem([this](Otter::Core::Orchestrator& o)                                                 \
                                  { this->_luaContext.callFn("__callScripts", "", "s", #phase); },                     \
                                  Otter::Core::SystemManager::phase)


namespace Otter::Scripting {
    // static const std::string getTableLenght

    void ScriptingManager::enableScripting(std::string scriptingEntrypointFile)
    {
        _luaContext.doFile(scriptingEntrypointFile + "/OtterLib.lua");
        _luaContext.doFile(scriptingEntrypointFile + "/main.lua");
        _luaContext.doString(luaCallScripts);
        std::cout << "[OtterLib] Scripts loaded" << std::endl;

        _luaContext.setGlobal("__orchestrator", &_orchestrator);
        _luaContext.registerFunction("__createEntity", Otter::Scripting::Bindings::Orchestrator::createEntity);
        _luaContext.registerFunction("__removeEntity", Otter::Scripting::Bindings::Orchestrator::removeEntity);

        this->setupComponentBindings();

        REGISTER_SYSTEM(init);
        REGISTER_SYSTEM(preEvent);
        REGISTER_SYSTEM(event);
        REGISTER_SYSTEM(preUpdate);
        REGISTER_SYSTEM(update);
        REGISTER_SYSTEM(preDraw);
        REGISTER_SYSTEM(draw);
        REGISTER_SYSTEM(subDraw);
        REGISTER_SYSTEM(cleanup);

        std::cout << "[OtterLib] Scripting initialized" << std::endl;
    }

    void ScriptingManager::setupComponentBindings(void)
    {
        _luaContext.registerFunction("__Window_setWidth", Otter::Scripting::Bindings::BaseComponents::Window::set_width);
        _luaContext.registerFunction("__Window_getWidth", Otter::Scripting::Bindings::BaseComponents::Window::get_width);
        _luaContext.registerFunction("__Window_getHeight", Otter::Scripting::Bindings::BaseComponents::Window::get_height);
        _luaContext.registerFunction("__Window_setHeight", Otter::Scripting::Bindings::BaseComponents::Window::set_height);
        _luaContext.registerFunction("__Window_getFps", Otter::Scripting::Bindings::BaseComponents::Window::get_fps);
        _luaContext.registerFunction("__Window_setFps", Otter::Scripting::Bindings::BaseComponents::Window::set_fps);
        _luaContext.registerFunction("__Window_getTitle", Otter::Scripting::Bindings::BaseComponents::Window::get_title);
        _luaContext.registerFunction("__Window_setTitle", Otter::Scripting::Bindings::BaseComponents::Window::set_title);
        _luaContext.registerFunction("__Window_createAndAdd", Otter::Scripting::Bindings::BaseComponents::Window::createAndAdd);
        _luaContext.registerFunction("__Window_delete", Otter::Scripting::Bindings::Templates::removeComponent<Core::BaseComponents::Window>);
    }

} // namespace Otter::Scripting
