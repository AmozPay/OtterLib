#include "ScriptingManager.hpp"

#include "OtterCore.hpp"

#include <gtest/gtest.h>
#include <string>

void Otter::Core::registerSystems(Otter::Core::SystemManager& s) {}

void Otter::Core::createEntityObj(Otter::Core::Orchestrator& o) {}

void Otter::Core::registerComponents(Otter::Core::Orchestrator& o) {}

void Otter::Core::configureScripting(Otter::Scripting::ScriptingManager& scriptingManager) {}

TEST(scriptingManagerLuaBindings, shouldPrintHi)
{
    Otter::Scripting::LuaContext luaContext;

    luaContext.doFile("test_data/OtterLib.lua");
    luaContext.doString(Otter::Scripting::luaCallScripts);
    luaContext.doString("function sayHi()\n  print('hi')\n end");
    luaContext.doString("OtterLib.systems.register(sayHi, OtterLib.systems.phasesEnum.init)");
    auto callScripts = luaContext.bind<char const*>("__callScripts", "", "s");
    testing::internal::CaptureStdout();
    callScripts("init");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "hi\n");
}