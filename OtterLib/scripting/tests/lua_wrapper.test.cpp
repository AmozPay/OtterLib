#include "lua_wrapper.hpp"
#include "lua.h"
#include <gtest/gtest.h>
#include <string>

struct st_my_struct {
    int nb;
    char const* str;
};

TEST(doFile, should_load)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doFile("test_data/hello.lua");
}

TEST(doFile, should_throw_runtime_error)
{
    Otter::Scripting::LuaContext ctx;

    EXPECT_THROW(ctx.doFile("test_data/doesNotExists.lua"), std::runtime_error);
}

TEST(callFn, shouldAdd)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doFile("test_data/functions.lua");
    lua_Integer sum = std::get<lua_Integer>(ctx.callFn("add", "i", "ii", 1, 1)[0]);
    EXPECT_EQ(sum, 2);
}

TEST(callFn, shouldReturn2longs)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doFile("test_data/functions.lua");
    std::vector<Otter::Scripting::luaTypes> retVals = ctx.callFn("tuple_of_2s", "ii");
    EXPECT_EQ(std::get<lua_Integer>(retVals[0]), 2);
    EXPECT_EQ(std::get<lua_Integer>(retVals[1]), 2);
}

TEST(callFn, shouldReturn3strings)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doFile("test_data/functions.lua");
    std::vector<Otter::Scripting::luaTypes> retVals = ctx.callFn("return_3_string", "sss");
    EXPECT_EQ(std::string(std::get<char const*>(retVals[0])), "foo");
    EXPECT_EQ(std::string(std::get<char const*>(retVals[1])), "bar");
    EXPECT_EQ(std::string(std::get<char const*>(retVals[2])), "baz");
}

TEST(callFn, shouldReturnSelf)
{
    Otter::Scripting::LuaContext ctx;

    const struct st_my_struct my_struct = {.nb = 5, .str = "hi from fonseca"};
    ctx.doString("function returnSelf(i) return i end");
    std::vector<Otter::Scripting::luaTypes> retVals = ctx.callFn("returnSelf", "p", "p", &my_struct);

    EXPECT_EQ(&my_struct, std::get<void*>(retVals[0]));
}

TEST(callFn, shouldThrowErr)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doFile("test_data/functions.lua");
    EXPECT_THROW(ctx.callFn("doesNotExist", "i", "ii", 1, 1), Otter::Scripting::LuaError);
}

TEST(stdOutChecks, should_print_hello)
{
    Otter::Scripting::LuaContext ctx;

    testing::internal::CaptureStdout();
    ctx.doString("print(\"Hello\")");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));

    testing::internal::CaptureStdout();
    ctx.doFile("test_data/hello.lua");
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));

    testing::internal::CaptureStdout();
    ctx.callFn("printHello", "");
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));
}

TEST(bind, bindAddShouldAdd)
{

    Otter::Scripting::LuaContext ctx;

    ctx.doString("function add(x, y) return x + y end");
    auto addFromLua = ctx.bind<int, int>("add", "i", "ii");
    auto res = addFromLua(1, 2);
    std::vector<Otter::Scripting::luaTypes> retVals = addFromLua(1, 2);
    EXPECT_EQ(std::get<lua_Integer>(retVals[0]), 3);
}

TEST(bind, bindShouldConcatStrings)
{

    Otter::Scripting::LuaContext ctx;

    ctx.doString("function concat(str1, str2) return str1 .. str2 end");
    auto concatFromLua = ctx.bind<char const*, char const*>("concat", "s", "ss");
    auto retVals = concatFromLua("hello ", "world");
    EXPECT_EQ(std::string(std::get<char const*>(retVals[0])), "hello world");
}

TEST(luaValues, getGlobalVariableAsInteger)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doString("a = 5");
    EXPECT_EQ(ctx["a"].toInteger(), 5);
}

TEST(luaValues, getGlobalVariableAsString)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doString("a = 'coucou'");
    EXPECT_EQ(ctx["a"].toString(), "coucou");
}

TEST(luaValues, getGlobalVariableAsDouble)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doString("a = 3.14");
    EXPECT_EQ(ctx["a"].toDouble(), 3.14);
}

TEST(luaValues, getValueInTable)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doString("a = {}\na['foo'] = 'bar'");
    Otter::Scripting::LuaValue a = ctx["a"];
    Otter::Scripting::LuaValue foo = a["foo"];
    EXPECT_EQ(ctx["a"]["foo"].toString(), "bar");
    EXPECT_EQ(a["foo"].toString(), "bar");
    EXPECT_EQ(foo.toString(), "bar");
}

TEST(luaValues, getValueInTableNested)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doString("foo = {}");
    ctx.doString("foo['bar'] = 'baz'");
    ctx.doString("a = {}\na['foo'] = foo");
    EXPECT_TRUE(ctx["foo"].isTable());
    EXPECT_EQ(ctx["a"]["foo"]["bar"].toString(), "baz");
    Otter::Scripting::LuaValue a = ctx["a"];
    Otter::Scripting::LuaValue foo = a["foo"];
    Otter::Scripting::LuaValue bar = foo["bar"];
    EXPECT_EQ(a["foo"]["bar"].toString(), "baz");
    EXPECT_EQ(foo["bar"].toString(), "baz");
    EXPECT_EQ(bar.toString(), "baz");
}

TEST(getTableLen, shouldReturnTableLen)
{
    Otter::Scripting::LuaContext ctx;

    ctx.doString("foo = {bar = {1,2,3,4,5}}");
    EXPECT_EQ(ctx["foo"]["bar"].getTableLength(), 5);
}
