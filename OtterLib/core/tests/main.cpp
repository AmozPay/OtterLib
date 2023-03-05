#include "OtterCore.hpp"
#include "test.hpp"

void Otter::Core::registerComponents(Otter::Core::Orchestrator& orchestrator) {}

void Otter::Core::registerSystems(Otter::Core::SystemManager& manager) {}

void Otter::Core::createEntityObj(Otter::Core::Orchestrator&){};
void Otter::Core::configureScripting(Otter::Scripting::ScriptingManager& scriptingManager) {}

TEST(TestSuiteName, TestName) { EXPECT_TRUE(true); }

TEST_F(sparse_arrayTest, IsEmptyInitialisze)
{
    EXPECT_EQ(f0.size(), 0);
    EXPECT_TRUE(f0.isEmpty());
}

TEST_F(sparse_arrayTest, Inserting)
{
    EXPECT_EQ(f1.size(), 0);
    f1.insert_at(0, 42);
    EXPECT_EQ(f1.size(), 1);
}

TEST_F(sparse_arrayTest, AccesData) { EXPECT_TRUE(f2[0]); }

TEST_F(sparse_arrayTest, AccesOptional)
{
    EXPECT_EQ(f3.size(), 4);
    EXPECT_TRUE(f3[0]);
    EXPECT_EQ(f3[0].value(), 41);

    EXPECT_TRUE(f3[1]);
    EXPECT_EQ(f3[1].value(), 42);
    EXPECT_TRUE(!(f3[2]));

    EXPECT_TRUE(f3[3]);
    EXPECT_EQ(*(f3[3]), 43);
}

TEST_F(sparse_arrayTest, findIndex)
{
    EXPECT_EQ(f3.size(), 4);
    EXPECT_TRUE(f3[3]);
    auto const& it = f3[3];
    auto const& it2 = f3[0];

    EXPECT_EQ(f3.get_index(it), 3);
    EXPECT_EQ(f3.get_index(it2), 0);
}

TEST_F(sparse_arrayTest, erasing)
{
    EXPECT_EQ(f3.size(), 4);
    EXPECT_TRUE(f3[1]);
    EXPECT_TRUE(!(f3[2]));
    f3.erase(1);
    f3.erase(2);
    EXPECT_TRUE(!(f3[1]));
    EXPECT_TRUE(!(f3[2]));
    EXPECT_EQ(f3.size(), 4);
}

/*
TEST_F(sparse_arrayTest, emplace_at_basic)
{
  EXPECT_TRUE(f4.isEmpty());
  f4.emplace_at(0, 10);
  EXPECT_EQ(f4.size(), 1);
  EXPECT_TRUE(f4[0]);
  EXPECT_EQ(f4[0].value().getDt(), 10);
}

TEST_F(sparse_arrayTest, emplace_at_complex)
{
    EXPECT_TRUE(f4.isEmpty());
  f4.emplace_at(2, 42);
  EXPECT_EQ(f4.size(), 3);
  EXPECT_TRUE(!(f4[0]));
  EXPECT_TRUE(!(f4[1]));
  EXPECT_TRUE(f4[2]);
  EXPECT_EQ(f4[4]->getDt(), 42);
}
  */
