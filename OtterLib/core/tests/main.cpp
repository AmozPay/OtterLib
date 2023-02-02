#include "OtterCore.hpp"

#include <gtest/gtest.h>

void Otter::Core::registerComponents(Otter::Core::Orchestrator& orchestrator) {}

void Otter::Core::registerSystems(Otter::Core::SystemManager& manager) {}

TEST(TestSuiteName, TestName) { EXPECT_TRUE(true); }
