#include "test.hpp"

TEST(registry, test_register_new_composant)
{
    Otter::Core::ComponentManager registry;

    registry.register_component<intTest>();
    auto const& tmp = registry.get_components<intTest>();
    EXPECT_TRUE((std::is_same<decltype(tmp), const Otter::Core::sparse_array<intTest>&>::value));
    EXPECT_TRUE(tmp.isEmpty());
}

TEST(registry, test_add_composant)
{
    Otter::Core::ComponentManager registry;
    auto const& tmp2 = registry.register_component<intTest>();
    auto const& tmp = registry.get_components<intTest>();
    //  EXPECT_EQ(tmp, tmp2);
    auto& v2 = registry.add_component(1, intTest(42));
    auto& v1 = registry.add_component(3, intTest(3));
    EXPECT_EQ(tmp.size(), 4);
    EXPECT_TRUE(tmp[1]);
    EXPECT_TRUE(tmp[3]);
    EXPECT_TRUE(!(tmp[0]));
    EXPECT_EQ(tmp[3].value().getDt(), 3);
    v1->setDt(10);
    EXPECT_EQ(tmp[3]->getDt(), 10);
}

TEST(registry, test_remove)
{
    Otter::Core::ComponentManager registry;
    auto const& tmp = registry.register_component<intTest>();
    auto& v1 = registry.add_component(1, intTest(42));
    auto& v2 = registry.add_component(3, intTest(3));
    EXPECT_EQ(tmp.size(), 4);
    EXPECT_TRUE(tmp[1]);
    EXPECT_TRUE(tmp[3]);

    registry.remove_component<intTest>(2);
    EXPECT_EQ(tmp.size(), 4);
    EXPECT_TRUE(tmp[1]);
    EXPECT_TRUE(tmp[3]);
    registry.remove_component<intTest>(3);

    EXPECT_EQ(tmp.size(), 4);
    EXPECT_TRUE(tmp[1]);
    EXPECT_TRUE(!(tmp[3]));
}
