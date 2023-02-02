#include "test.hpp"

TEST(registry, test_register_new_composant)
{
    Otter::Core::ComponentManager registry;

    registry.register_component<intTest>();
    auto const& tmp = registry.get_components<intTest>();
    EXPECT_TRUE((std::is_same<decltype(tmp), const Otter::Core::sparse_array<intTest>&>::value));
    EXPECT_TRUE(tmp.isEmpty());
}
