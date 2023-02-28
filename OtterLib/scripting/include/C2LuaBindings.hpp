
#pragma once
#include "baseComponents.hpp"

///////////////////////////////////////////////////////////////////////////////
/////////////////////   GETTER / SETTER MACROS   //////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// CLB_STRING_GSETTER: automatic creation of Lua bindings for getter and setter of a string component property
#define CLB_STRING_GSETTER(componentType, memberName) int set_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ls");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto component = orchestrator->get_components<Otter::Core::BaseComponents::componentType>()[entity];\
    (*component)._ ## memberName = std::string(std::get<char const *>(args[1]));\
    return 0;\
} \
int get_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("l");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto component = orchestrator->get_components<Otter::Core::BaseComponents::componentType>()[entity];\
    ctx.push(component->_ ## memberName .c_str());\
    return 1;\
}

// CLB_INT_GSETTER: automatic creation of Lua bindings for getter and setter of an int type component property
#define CLB_INT_GSETTER(componentType, memberName) int set_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ll");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto component = orchestrator->get_components<Otter::Core::BaseComponents::componentType>()[entity];\
    (*component)._ ## memberName = std::get<long long>(args[1]);\
    return 0;\
}\
int get_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("l");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto component = orchestrator->get_components<Otter::Core::BaseComponents::componentType>()[entity];\
    ctx.push(static_cast<long long>(component->_ ## memberName));\
    return 1;\
}

// CLB_NUMBER_GSETTER: automatic creation of Lua bindings for getter and setter of a numer type component property
#define CLB_NUMBER_GSETTER(componentType, memberName) int set_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ll");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto component = orchestrator->get_components<Otter::Core::BaseComponents::componentType>()[entity];\
    (*component)._ ## memberName = std::get<double>(args[1]);\
    return 0;\
}\
int get_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("l");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto component = orchestrator->get_components<Otter::Core::BaseComponents::componentType>()[entity];\
    ctx.push(static_cast<double>(component->_ ## memberName));\
    return 1;\
}


// CLB_BOOL_GSETTER: automatic creation of Lua bindings for getter and setter of a bool type component property
#define CLB_BOOL_GSETTER(componentType, memberName) int set_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("lb");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto component = orchestrator->get_components<Otter::Core::BaseComponents::componentType>()[entity];\
    (*component)._ ## memberName = std::get<bool>(args[1]);\
    return 0;\
}\
int get_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("l");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto component = orchestrator->get_components<Otter::Core::BaseComponents::componentType>()[entity];\
    ctx.push(static_cast<bool>(component->_ ## memberName));\
    return 1;\
}


// CLB_VECTOR2_GSETTER: automatic creation of Lua bindings for getter and setter of a Vector2 type component property
#define CLB_VECTOR2_GSETTER(componentType, memberName) int set_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ldd");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    float x = std::get<double>(args[1]);\
    float y = std::get<double>(args[2]);\
    orchestrator->get_components<Core::BaseComponents::componentType>()[entity]->_ ## memberName = {.x = x, .y = y};\
    return 0;\
}\
int get_ ## memberName(lua_State *L) {\
    Otter::Scripting::LuaContext ctx(L);\
    Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());\
    std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("l");\
    auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));\
    auto vec = orchestrator->get_components<Core::BaseComponents::componentType>()[entity]->_ ## memberName;\
    ctx.push(static_cast<double>(vec.x));\
    ctx.push(static_cast<double>(vec.y));\
    return 2;\
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////   BINDINGS   ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

namespace Otter::Scripting::Bindings::Orchestrator
{
    int createEntity(lua_State *L);
    int removeEntity(lua_State *L);
} // namespace Otter::Scripting::Bindings

namespace Otter::Scripting::Bindings::Templates {
    template<typename T>
    int addEmptyComponent(lua_State *L)
    {
        Otter::Scripting::LuaContext ctx(L);
        Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
        std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("l");
        auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
        orchestrator->add_component<T>(entity, T());
        return 0;
    }

    // Can be used to delete any type of component, but each component deleter be registered to lua like so:
    // _luaContext.registerFunction("__removeComponent.MyComponent", Otter::Scripting::Bindings::Templates::removeComponent<MyComponent>);
    template<typename T>
    int removeComponent(lua_State *L)
    {
        Otter::Scripting::LuaContext ctx(L);
        Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
        std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("l");
        auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
        orchestrator->remove_component<T>(entity);
        return 0;
    }
}

namespace Otter::Scripting::Bindings {
    class EnumException {
        public:
            EnumException(std::string str): _what(str) {}
            std::string what()
            {
                return _what;
            }

        private:
            std::string _what;
    };
}

namespace Otter::Scripting::Bindings::BaseComponents {

    // TODO: Texture, Keyboard
    namespace Window {
        CLB_INT_GSETTER(Window, width)
        CLB_INT_GSETTER(Window, height)
        CLB_INT_GSETTER(Window, fps)
        CLB_STRING_GSETTER(Window, title)
        int createAndAdd(lua_State *L);
    }

    namespace BoxCollider {
        CLB_NUMBER_GSETTER(BoxCollider, width)
        CLB_NUMBER_GSETTER(BoxCollider, height)

        int createAndAdd(lua_State *L);
    }

    namespace Sound {
        CLB_STRING_GSETTER(Sound, path)
        CLB_NUMBER_GSETTER(Sound, volume)
        int set_status(lua_State *L);
        int get_status(lua_State *L);
        int createAndAdd(lua_State *L);
    }

    namespace Music {
        CLB_STRING_GSETTER(Music, path)
        CLB_NUMBER_GSETTER(Music, volume)
        CLB_BOOL_GSETTER(Music, isLooping)
        int set_status(lua_State *L);
        int get_status(lua_State *L);
        int createAndAdd(lua_State *L);
    }

    namespace Transform {
        CLB_NUMBER_GSETTER(Transform, rotation)
        CLB_NUMBER_GSETTER(Transform, scale)
        CLB_VECTOR2_GSETTER(Transform, position)
        CLB_VECTOR2_GSETTER(Transform, lastPosition)
        int createAndAdd(lua_State *L);
    }

    namespace Velocity {
        CLB_NUMBER_GSETTER(Velocity, speed)
        CLB_NUMBER_GSETTER(Velocity, constantSpeed)
        CLB_VECTOR2_GSETTER(Velocity, accelerationDirection)
        CLB_VECTOR2_GSETTER(Velocity, constantAccelerationDirection)
        int createAndAdd(lua_State *L);
    }

    namespace Player {
        CLB_INT_GSETTER(Player, id)
        CLB_STRING_GSETTER(Player, tag)
        int createAndAdd(lua_State *L);
    }

    namespace Enemy {
        CLB_INT_GSETTER(Enemy, id)
        CLB_STRING_GSETTER(Enemy, tag)
        int createAndAdd(lua_State *L);
    }

    namespace Health {
        CLB_INT_GSETTER(Health, hp)
        int createAndAdd(lua_State *L);
    }

    namespace Damage {
        CLB_INT_GSETTER(Damage, damage)
        int createAndAdd(lua_State *L);
    }

    namespace Destructible {
        CLB_BOOL_GSETTER(Destructible, isDestructible)
        int createAndAdd(lua_State *L);
    }


} // namespace Otter::Scripting::Bindings::BaseComponents
