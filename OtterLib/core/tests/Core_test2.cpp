#include "test.hpp"

TEST(Entity, construct)
{
  Otter::Core::EntityManager manager;

  EXPECT_TRUE(true);
}

TEST(Entity, register_entity)
{
  Otter::Core::EntityManager man;

   Otter::Core::Entity e1 = man.CreateEntity();
   Otter::Core::Entity e2 = man.CreateEntity();
  EXPECT_TRUE(e1 != e2);
}

TEST(Entity, ReuseEntity)
{
  Otter::Core::EntityManager man;

   Otter::Core::Entity e1 = man.CreateEntity();
   Otter::Core::Entity e2 = man.CreateEntity();
  EXPECT_TRUE(e1 != e2);
  man.destroyEntity(e1);
   Otter::Core::Entity e3 = man.CreateEntity();
  EXPECT_TRUE(e1 == e3);
}
