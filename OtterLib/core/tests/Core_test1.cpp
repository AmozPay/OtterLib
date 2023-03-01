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

/*
TEST(registry_index, get_component_index)
{
    Otter::Core::ComponentManager reg;
    auto const& tmp = reg.register_component<intTest>();
    auto const& tmp2 = reg.register_component<float>();
    auto const& tmp3 = reg.register_component<std::string>();

    reg.add_component<float>(2, 25.5);
    reg.add_component<intTest>(1, intTest(5));
    reg.add_component<intTest>(2, intTest(10));

    auto idx1 = reg.get_index_type<intTest>();
    auto idx2 = reg.get_index_type<float>();
    auto idx3 = reg.get_index_type<std::string>();

    auto tm = get_component_index(idx1);
    EXPECT_EQ(tm.size(), tmp.size());
    auto tm1 = get_component_index(idx2);
    EXPECT_EQ(tm1.size(), tmp2.size());
    auto tm2 = get_component_index(idx3);
    EXPECT_EQ(tm2.size(), tmp3.size());
}
*/
TEST(registry_advanced, test_multipl_comp)
{
    Otter::Core::ComponentManager reg;

    auto const& tmp = reg.register_component<intTest>();
    auto const& tmp2 = reg.register_component<float>();
    auto const& tmp3 = reg.register_component<std::string>();

    reg.add_component<float>(0, 5.3);
    reg.add_component<float>(2, 25.5);

    reg.add_component<intTest>(1, intTest(5));
    reg.add_component<intTest>(2, intTest(10));
    reg.add_component<intTest>(3, intTest(15));

    reg.add_component(0, std::string("un"));
    reg.add_component(2, std::string("deux"));

    EXPECT_EQ(tmp.size(), 4);
    EXPECT_EQ(tmp2.size(), 3);
    EXPECT_EQ(tmp3.size(), 3);

    EXPECT_TRUE(tmp[1]);
    reg.remove_component<intTest>(1);
    EXPECT_FALSE(tmp[1]);
    EXPECT_TRUE(tmp[2]);
    EXPECT_TRUE(tmp2[2]);
    EXPECT_TRUE(tmp3[2]);
    reg.remove_entity(2);
    EXPECT_FALSE(tmp[2]);
    EXPECT_FALSE(tmp2[2]);
    EXPECT_FALSE(tmp3[2]);

    EXPECT_TRUE(tmp[3]);
    reg.remove_entity(3);
    EXPECT_FALSE(tmp[3]);
}

TEST(Orchestrator, test_remove_a_entity)
{
    Otter::Core::Factory f;
    Otter::Core::Orchestrator orch(f);

    auto const& tmp = orch.register_component<intTest>();
    auto const& tmp2 = orch.register_component<float>();
    auto const& tmp3 = orch.register_component<std::string>();

    Otter::Core::Entity e1 = orch.createEntity();
    Otter::Core::Entity e2 = orch.createEntity();
    Otter::Core::Entity e3 = orch.createEntity();
    Otter::Core::Entity e4 = orch.createEntity();

    orch.add_component<float>(e1, 5.3);
    orch.add_component<float>(e3, 25.5);

    orch.add_component<intTest>(e2, intTest(5));
    orch.add_component<intTest>(e3, intTest(10));
    orch.add_component<intTest>(e4, intTest(15));

    orch.add_component(e1, std::string("un"));
    orch.add_component(e3, std::string("deux"));

    EXPECT_EQ(tmp.size(), e4 +1);
    EXPECT_EQ(tmp2.size(), e4);
    EXPECT_EQ(tmp3.size(), e4);

    EXPECT_TRUE(tmp[e2]);
    orch.remove_component<intTest>(e2);
    EXPECT_FALSE(tmp[e2]);
    EXPECT_TRUE(tmp[e3]);
    EXPECT_TRUE(tmp2[e3]);
    EXPECT_TRUE(tmp3[e3]);

    orch.remove_entity(e3);
    
    EXPECT_FALSE(tmp[e3]);
    EXPECT_FALSE(tmp2[e3]);
    EXPECT_FALSE(tmp3[e3]);

    EXPECT_TRUE(tmp[e4]);
    orch.remove_entity(e4);
    EXPECT_FALSE(tmp[e4]);
}
