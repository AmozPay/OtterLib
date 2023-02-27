#include "lua_wrapper.hpp"
#include "Orchestrator.hpp"

namespace Otter::Scripting::Bindings {

    int createEntity(lua_State *L)
    {
        Otter::Scripting::LuaContext ctx(L);
        Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
        Otter::Core::Entity e = orchestrator->createEntity();
        ctx.push(static_cast<long long>(e));
        return 1;
    }

    int removeEntity(lua_State *L)
    {
        Otter::Scripting::LuaContext ctx(L);
        Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
        std::vector<Otter::Scripting::luaTypes> args = ctx.getStackValues("l", false);
        auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
        Otter::Core::Entity e = orchestrator->createEntity();
        std::cout << e << std::endl;
        orchestrator->remove_entity(entity);
        return 0;
    }

} // namespace Otter::Scripting