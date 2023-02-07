#include <gtest/gtest.h>
#include "script.hpp"
#include <string>


// class LuaTest : public ::testing::Test {
//  protected:
//   void SetUp() override {
//     lua.loadFile("test.lua");
//   }

//   // void TearDown() override {}

//   Otter::Script::Lua lua;
// };

TEST(loadFile, should_load)
{
    Otter::Script::Lua lua;

    lua.loadFile("build/test_data/test.lua");
}

TEST(callFn, should_print_hello)
{
    Otter::Script::Lua lua;

    lua.loadFile("build/test_data/test.lua");
    testing::internal::CaptureStdout();
    lua.callFn("printHello", "");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));
}

TEST(doFile, should_print_hello)
{
    Otter::Script::Lua lua;

    testing::internal::CaptureStdout();
    lua.doFile("build/test_data/hello.lua");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));
}

TEST(loadFile, should_throw_runtime_error)
{
    Otter::Script::Lua lua;

    EXPECT_THROW(lua.loadFile("build/test_data/doesNotExists.lua"), std::runtime_error);
}

TEST(doString, should_print_hello)
{
    Otter::Script::Lua lua;

    testing::internal::CaptureStdout();
    int res = lua.doString("print(\"Hello\")");
    EXPECT_EQ(res, 0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("Hello\n"));
}