#include <gtest/gtest.h>
#include "lua_wrapper.hpp"
#include <string>

struct st_my_struct {
    int nb;
    char const *str;
};

using luaTypes = std::variant<long long, double, bool, std::string, void *>;


TEST(doFile, should_load)
{
    Otter::Script::LuaContext ctx;

    ctx.doFile("build/test_data/hello.lua");
}


TEST(doFile, should_throw_runtime_error)
{
    Otter::Script::LuaContext ctx;

    EXPECT_THROW(ctx.doFile("build/test_data/doesNotExists.lua"), std::runtime_error);
}

TEST(callFn, shouldAdd)
{
    Otter::Script::LuaContext ctx;

    ctx.doFile("build/test_data/functions.lua");
    long long sum = std::get<long long>(ctx.callFn("add", "l", "ll", 1, 1)[0]);
    EXPECT_EQ(sum, 2);
}

TEST(callFn, shouldReturn2longs)
{
    Otter::Script::LuaContext ctx;

    ctx.doFile("build/test_data/functions.lua");
    std::vector<luaTypes> retVals = ctx.callFn("tuple_of_2s", "ll");
    EXPECT_EQ(std::get<long long>(retVals[0]), 2);
    EXPECT_EQ(std::get<long long>(retVals[1]), 2);
}

TEST(callFn, shouldReturn3strings)
{
    Otter::Script::LuaContext ctx;

    ctx.doFile("build/test_data/functions.lua");
    std::vector<luaTypes> retVals = ctx.callFn("return_3_string", "sss");
    EXPECT_EQ(std::get<std::string>(retVals[0]), "foo");
    EXPECT_EQ(std::get<std::string>(retVals[1]), "bar");
    EXPECT_EQ(std::get<std::string>(retVals[2]), "baz");
}

TEST(callFn, shouldReturnSelf)
{
    Otter::Script::LuaContext ctx;

    const struct st_my_struct my_struct = {.nb = 5, .str = "hi from fonseca"};
    ctx.doString("function returnSelf(i) return i end");
    std::vector<luaTypes> retVals = ctx.callFn("returnSelf", "p", "p", &my_struct);

    EXPECT_EQ(&my_struct, std::get<void *>(retVals[0]));
}

TEST(callFn, shouldThrowErr)
{
    Otter::Script::LuaContext ctx;

    ctx.doFile("build/test_data/functions.lua");
    EXPECT_THROW(ctx.callFn("doesNotExist", "l", "ll", 1, 1), Otter::Script::LuaError);
}

TEST(stdOutChecks, should_print_hello)
{
    Otter::Script::LuaContext ctx;

    testing::internal::CaptureStdout();
    ctx.doString("print(\"Hello\")");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));

    testing::internal::CaptureStdout();
    ctx.doFile("build/test_data/hello.lua");
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));

    testing::internal::CaptureStdout();
    ctx.callFn("printHello", "");
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));
}

TEST(bind, bindAddShouldAdd)
{

    Otter::Script::LuaContext ctx;

    ctx.doString("function add(x, y) return x + y end");
    auto addFromLua = ctx.bind<int, int>("add", "l", "ll");
    auto res = addFromLua(1, 2);
    std::vector<luaTypes> retVals = addFromLua(1, 2);
    EXPECT_EQ(std::get<long long>(retVals[0]), 3);
}

TEST(luaValues, getGlobalVariableAsInteger)
{
    Otter::Script::LuaContext ctx;

    ctx.doString("a = 5");
    EXPECT_EQ(ctx["a"].toInteger(), 5);
}

TEST(luaValues, getGlobalVariableAsString)
{
    Otter::Script::LuaContext ctx;

    ctx.doString("a = 'coucou'");
    EXPECT_EQ(ctx["a"].toString(), "coucou");
}

TEST(luaValues, getValueInTable)
{
    Otter::Script::LuaContext ctx;

    ctx.doString("a = {}\na['foo'] = 'bar'");
    Otter::Script::LuaValue a = ctx["a"];
    Otter::Script::LuaValue foo = a["foo"];
    EXPECT_EQ(ctx["a"]["foo"].toString(), "bar");
    EXPECT_EQ(a["foo"].toString(), "bar");
    EXPECT_EQ(foo.toString(), "bar");
}

TEST(luaValues, getValueInTableNested)
{
    Otter::Script::LuaContext ctx;

    ctx.doString("foo = {}");
    ctx.doString("foo['bar'] = 'baz'");
    ctx.doString("a = {}\na['foo'] = foo");
    EXPECT_TRUE(ctx["foo"].isTable());
    EXPECT_EQ(ctx["a"]["foo"]["bar"].toString(), "baz");
    Otter::Script::LuaValue a = ctx["a"];
    Otter::Script::LuaValue foo = a["foo"];
    Otter::Script::LuaValue bar = foo["bar"];
    EXPECT_EQ(a["foo"]["bar"].toString(), "baz");
    EXPECT_EQ(foo["bar"].toString(), "baz");
    EXPECT_EQ(bar.toString(), "baz");
}
