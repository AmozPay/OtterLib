#include <gtest/gtest.h>
#include "script.hpp"
#include <string>


// class LuaTest : public ::testing::Test {
//  protected:
//   void SetUp() override {
//     lua.doFile("test.lua");
//   }

//   // void TearDown() override {}

//   Otter::Script::Lua lua;
// };

struct st_my_struct {
    int nb;
    char const *str;
};

using luaTypes = std::variant<long long, double, bool, std::string, void *>;


TEST(doFile, should_load)
{
    Otter::Script::Lua lua;

    lua.doFile("build/test_data/hello.lua");
}


TEST(doFile, should_throw_runtime_error)
{
    Otter::Script::Lua lua;

    EXPECT_THROW(lua.doFile("build/test_data/doesNotExists.lua"), std::runtime_error);
}

TEST(callFn, shouldAdd)
{
    Otter::Script::Lua lua;

    lua.doFile("build/test_data/functions.lua");
    long long sum = std::get<long long>(lua.callFn("add", "l", "ll", 1, 1)[0]);
    EXPECT_EQ(sum, 2);
}

TEST(callFn, shouldReturn2longs)
{
    Otter::Script::Lua lua;

    lua.doFile("build/test_data/functions.lua");
    std::vector<luaTypes> retVals = lua.callFn("tuple_of_2s", "ll");
    EXPECT_EQ(std::get<long long>(retVals[0]), 2);
    EXPECT_EQ(std::get<long long>(retVals[1]), 2);
}

TEST(callFn, shouldReturn3strings)
{
    Otter::Script::Lua lua;

    lua.doFile("build/test_data/functions.lua");
    std::vector<luaTypes> retVals = lua.callFn("return_3_string", "sss");
    EXPECT_EQ(std::get<std::string>(retVals[0]), "foo");
    EXPECT_EQ(std::get<std::string>(retVals[1]), "bar");
    EXPECT_EQ(std::get<std::string>(retVals[2]), "baz");
}

TEST(callFn, shouldReturnSelf)
{
    Otter::Script::Lua lua;

    const struct st_my_struct my_struct = {.nb = 5, .str = "hi from fonseca"};
    lua.doString("function returnSelf(i) return i end");
    std::vector<luaTypes> retVals = lua.callFn("returnSelf", "p", "p", &my_struct);

    EXPECT_EQ(&my_struct, std::get<void *>(retVals[0]));
}

TEST(callFn, shouldThrowErr)
{
    Otter::Script::Lua lua;

    lua.doFile("build/test_data/functions.lua");
    EXPECT_THROW(lua.callFn("doesNotExist", "l", "ll", 1, 1), Otter::Script::Lua::LuaError);
}

TEST(stdOutChecks, should_print_hello)
{
    Otter::Script::Lua lua;

    testing::internal::CaptureStdout();
    lua.doString("print(\"Hello\")");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));

    testing::internal::CaptureStdout();
    lua.doFile("build/test_data/hello.lua");
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));

    testing::internal::CaptureStdout();
    lua.callFn("printHello", "");
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));
}

TEST(bind, bindAddShouldAdd)
{

    Otter::Script::Lua lua;

    lua.doString("function add(x, y) return x + y end");
    auto addFromLua = lua.bind<int, int>("add", "l", "ll");
    auto res = addFromLua(1, 2);
    std::vector<luaTypes> retVals = addFromLua(1, 2);
    EXPECT_EQ(std::get<long long>(retVals[0]), 3);
}