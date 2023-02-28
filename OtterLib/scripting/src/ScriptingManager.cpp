#include "ScriptingManager.hpp"
#include "C2LuaBindings.hpp"

#define REGISTER_SYSTEM(phase)                                                                                         \
    _systemManager.registerSystem([this](Otter::Core::Orchestrator& o)                                                 \
                                  { this->_luaContext.callFn("__callScripts", "", "s", #phase); },                     \
                                  Otter::Core::SystemManager::phase)

#define CLB_REGISTER_GSETTER_FUNCTION(componentName, property) \
    _luaContext.registerFunction("__" #componentName "_get_" #property, Bindings::BaseComponents::componentName::get_ ## property );\
    _luaContext.registerFunction("__" #componentName "_set_" #property, Bindings::BaseComponents::componentName::set_ ## property );

#define CLB_REGISTER_CD_FUNCTION(componentName) \
    _luaContext.registerFunction("__" #componentName "_createAndAdd", Bindings::BaseComponents::componentName::createAndAdd );\
    _luaContext.registerFunction("__" #componentName "_delete", Bindings::Templates::removeComponent<Core::BaseComponents::componentName> );


#define CLB_REGISTER_SIMPLE_COMPONENT(componentName) \
    _luaContext.registerFunction("__" #componentName "_createAndAdd", Bindings::Templates::addEmptyComponent<Core::BaseComponents::componentName> );\
    _luaContext.registerFunction("__" #componentName "_delete", Bindings::Templates::removeComponent<Core::BaseComponents::componentName> );


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
        this->registerComponents();

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

    void ScriptingManager::registerComponents(void)
    {
        _orchestrator.register_component<Core::BaseComponents::Render>();
        _orchestrator.register_component<Core::BaseComponents::Parallax>();
        _orchestrator.register_component<Core::BaseComponents::Dispawnable>();
        _orchestrator.register_component<Core::BaseComponents::Dispawnable>();
        _orchestrator.register_component<Core::BaseComponents::EventNetwork>();
        _orchestrator.register_component<Core::BaseComponents::Window>();
        _orchestrator.register_component<Core::BaseComponents::BoxCollider>();
        _orchestrator.register_component<Core::BaseComponents::Sound>();
        _orchestrator.register_component<Core::BaseComponents::Music>();
        _orchestrator.register_component<Core::BaseComponents::Transform>();
        _orchestrator.register_component<Core::BaseComponents::Velocity>();
        _orchestrator.register_component<Core::BaseComponents::Player>();
        _orchestrator.register_component<Core::BaseComponents::Enemy>();
        _orchestrator.register_component<Core::BaseComponents::Health>();
        _orchestrator.register_component<Core::BaseComponents::Damage>();
        _orchestrator.register_component<Core::BaseComponents::Destructible>();
    }

    void ScriptingManager::setupComponentBindings(void)
    {
        CLB_REGISTER_SIMPLE_COMPONENT(Render);
        CLB_REGISTER_SIMPLE_COMPONENT(Parallax);
        CLB_REGISTER_SIMPLE_COMPONENT(Dispawnable);
        CLB_REGISTER_SIMPLE_COMPONENT(EventNetwork);

        CLB_REGISTER_CD_FUNCTION(Window);
        CLB_REGISTER_GSETTER_FUNCTION(Window, width);
        CLB_REGISTER_GSETTER_FUNCTION(Window, height);
        CLB_REGISTER_GSETTER_FUNCTION(Window, fps);
        CLB_REGISTER_GSETTER_FUNCTION(Window, title);

        CLB_REGISTER_CD_FUNCTION(BoxCollider);
        CLB_REGISTER_GSETTER_FUNCTION(BoxCollider, width);
        CLB_REGISTER_GSETTER_FUNCTION(BoxCollider, height);

        CLB_REGISTER_CD_FUNCTION(Sound);
        CLB_REGISTER_GSETTER_FUNCTION(Sound, path);
        CLB_REGISTER_GSETTER_FUNCTION(Sound, volume);
        CLB_REGISTER_GSETTER_FUNCTION(Sound, status);

        CLB_REGISTER_CD_FUNCTION(Music);
        CLB_REGISTER_GSETTER_FUNCTION(Music, path);
        CLB_REGISTER_GSETTER_FUNCTION(Music, volume);
        CLB_REGISTER_GSETTER_FUNCTION(Music, status);

        CLB_REGISTER_CD_FUNCTION(Transform);
        CLB_REGISTER_GSETTER_FUNCTION(Transform, rotation);
        CLB_REGISTER_GSETTER_FUNCTION(Transform, scale);
        CLB_REGISTER_GSETTER_FUNCTION(Transform, position);
        CLB_REGISTER_GSETTER_FUNCTION(Transform, lastPosition);

        CLB_REGISTER_CD_FUNCTION(Velocity);
        CLB_REGISTER_GSETTER_FUNCTION(Velocity, speed);
        CLB_REGISTER_GSETTER_FUNCTION(Velocity, constantSpeed);
        CLB_REGISTER_GSETTER_FUNCTION(Velocity, accelerationDirection);
        CLB_REGISTER_GSETTER_FUNCTION(Velocity, constantAccelerationDirection);

        CLB_REGISTER_CD_FUNCTION(Player);
        CLB_REGISTER_GSETTER_FUNCTION(Player, id);
        CLB_REGISTER_GSETTER_FUNCTION(Player, tag);

        CLB_REGISTER_CD_FUNCTION(Enemy);
        CLB_REGISTER_GSETTER_FUNCTION(Enemy, id);
        CLB_REGISTER_GSETTER_FUNCTION(Enemy, tag);

        CLB_REGISTER_CD_FUNCTION(Health);
        CLB_REGISTER_GSETTER_FUNCTION(Health, hp);

        CLB_REGISTER_CD_FUNCTION(Damage);
        CLB_REGISTER_GSETTER_FUNCTION(Damage, damage);

        CLB_REGISTER_CD_FUNCTION(Destructible);
        CLB_REGISTER_GSETTER_FUNCTION(Destructible, isDestructible);
    }

} // namespace Otter::Scripting
