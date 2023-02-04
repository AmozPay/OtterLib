#include "test.hpp"

TEST(SystemManager, construct)
{
  Otter::Core::SystemManager manager;

  EXPECT_TRUE(true);
}

TEST_F(SystTest, construct2)
{
  Otter::Core::SystemManager &test = s1;
  EXPECT_TRUE(true);
}

TEST_F(SystTest, one_register)
{
  Otter::Core::Factory tmp2;
  Otter::Core::Orchestrator tmp(tmp2);

  testing::internal::CaptureStdout();
  s2(tmp, Otter::Core::SystemManager::Phase::init);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, std::string("s2.init\n"));
}

TEST_F(SystTest, call_phase)
{
  Otter::Core::Factory tmp2;
  Otter::Core::Orchestrator tmp(tmp2);

  testing::internal::CaptureStdout();

  s3(tmp, Otter::Core::SystemManager::Phase::init);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, std::string("s3.init\n"));


    testing::internal::CaptureStdout();

s3(tmp, Otter::Core::SystemManager::Phase::update);
  std::string out = testing::internal::GetCapturedStdout();
  EXPECT_EQ(out, std::string("s3.update\n"));
}

TEST_F(SystTest, order_same_phase)
{
  Otter::Core::Factory tmp2;
  Otter::Core::Orchestrator tmp(tmp2);

  testing::internal::CaptureStdout();

  s4(tmp, Otter::Core::SystemManager::Phase::init);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, std::string("s4.firsts4.third"));
    testing::internal::CaptureStdout();
  s4(tmp, Otter::Core::SystemManager::Phase::update);
  std::string out = testing::internal::GetCapturedStdout();
  EXPECT_EQ(out, std::string("s4.second"));
}
