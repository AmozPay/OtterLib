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
        std::cout << "Trying to remove an entity" << std::endl;
        std::vector<Otter::Scripting::luaTypes> args = ctx.getStackValues("l");
        std::cout << "Trying to remove an entity 2" << std::endl;
        std::cout << " len = " << args.size() << std::endl;
        auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
        std::cout << "Trying to remove an entity 3 " << entity << std::endl;
        orchestrator->remove_entity(entity);
        return 0;
    }

} // namespace Otter::Scripting