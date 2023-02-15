#include "ScriptingManager.hpp"

#include <gtest/gtest.h>
#include <string>


TEST(scriptingManagerLuaBindings, shouldPrintHi)
{
    Otter::Scripting::LuaContext luaContext;

    luaContext.doString(Otter::Scripting::luaSystemsTable);
    luaContext.doString(Otter::Scripting::luaCallScripts);
    luaContext.doString("function sayHi()\n  print('hi')\n end");
    luaContext.doString("table.insert(OtterSystems.init, sayHi)");
    auto callScripts = luaContext.bind<char const *>("__callScripts", "", "s");
    testing::internal::CaptureStdout();
    callScripts("init");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "hi\n");
}