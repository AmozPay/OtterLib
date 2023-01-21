#include "Orchestrator.hpp"

#include <iostream>

void compoTest(Otter::Core::Orchestrator& data, Otter::Core::sparse_array<testcomponent>& ref)
{
    int id = 1;

    std::optional<testcomponent>& reff = data.add_component(id, testcomponent(18));

    if (reff.has_value())
        std::cout << "contain value" << std::endl;
    if (reff.has_value() == false)
        std::cout << "no contain value" << std::endl;

    Otter::Core::ComponentManager::container_t<testcomponent>& get = data.get_components<testcomponent>();
    if (get.isEmpty())
        std::cout << "error: is empty" << std::endl;
    if (ref.isEmpty())
        std::cout << "error: refe don work" << std::endl;
    ref[id]->yolo();
    get[id]->yolo();
    data.remove_component<testcomponent>(id);
    if (get.isEmpty())
        std::cout << "error: need to be empty" << std::endl;
}

void init(Otter::Core::Orchestrator& data)
{
    auto type = data.register_component<testcomponent>();

    Otter::Core::ComponentManager::container_t<testcomponent>& get = data.get_components<testcomponent>();
    Otter::Core::ComponentManager::container_t<testcomponent> const& gets = data.get_components<testcomponent>();
    if (get.isEmpty())
        std::cout << "get is empty" << std::endl;
    if (gets.isEmpty())
        std::cout << "gets is empty" << std::endl;
    compoTest(data, get);
    std::cout << "register struct ?" << std::endl;
    auto type1 = data.register_component<test_str>();

    auto enti = data.createEntity();
    if (enti < 0)
        std::cout << "entity creat faile" << std::endl;

    std::optional<testcomponent>& reff = data.add_component(enti, testcomponent(18));
    std::optional<test_str>& reff2 = data.add_component(enti, test_str(19));
    data.remove_entity(enti);
    if (type1.isEmpty())
        std::cout << "entity clear" << std::endl;
    // registering
    // adding data
}

/*   EXEmple systeme
void logging_system ( registry & r ) {
  auto const & positions = r . get_components < component :: position >() ;
  auto const & velocities = r . get_components < component :: velocity >() ;
  for ( size_t i = 0; i < positions . size () && i < velocities . size () ; ++ i ) {
    auto const & pos = positions [ i ];
    auto const & vel = velocities [ i ];
    if ( pos && vel ) {
      std :: cerr << i << " : Position = { " << pos . value () . x << " , " << pos . value
        () . y << " } , Velocity = { " << vel . value () . vx << " , " << vel . value () .
        vy << " } " << std :: endl ;
    }
  }
  }*/

void print(Otter::Core::Orchestrator&) { std::cout << "workjn" << std::endl; }

void test_system(auto& data)
{
    Otter::Core::SystemManager sysTest;
    sysTest.register_system(&print);
    sysTest.run_systems(data);
}

int& fun(int& b) { return b; }

int main(int argc, char* argv[])
{
    //    Otter::Core::Orchestrator data;
    //    testref();
    //    test_system(data);
    //    init(data);
    //    while (1) {
    // system call Proto:
    //  void SYS_NAME(Orchestrator &data);
    //}
    return 0;
}

int& converte_any(int* var)
{
    *var = 4;
    return *var;
}

void test_ptr_to_ref()
{
    int var = 5;
    std::cout << var << std::endl; // expected 5

    int& var2 = converte_any(&var);
    std::cout << var << std::endl;  // expected 4
    std::cout << var2 << std::endl; // expected 4
    var2 = 8;
    std::cout << var << std::endl;  // expected 8
    std::cout << var2 << std::endl; // expected 8
}
