

#include "Orchestrator.hpp"

void compoTest(Core::Orchestrator &data, Core::sparse_array<testcomponent> &ref) {
    int id = 1;

    std::optional<testcomponent> &reff = data.add_component(id, testcomponent(18));

    if (reff.has_value())
        std::cout << "contain value" << std::endl;
    if (reff.has_value() == false)
        std::cout << "no contain value" << std::endl;

    Core::ComponentManager::container_t<testcomponent> &get = data.get_components<testcomponent>();
    if (get.isEmpty())
        std::cout << "error: is empty" << std::endl;
    if (ref.isEmpty())
        std::cout << "error: refe don work" << std::endl;
    ref[id]->yolo();
    get[id]->yolo();
}

void init(Core::Orchestrator &data) {
    auto type = data.register_component<testcomponent>();

    Core::ComponentManager::container_t<testcomponent> &get = data.get_components<testcomponent>();
    Core::ComponentManager::container_t<testcomponent> const &gets =
        data.get_components<testcomponent>();
    if (get.isEmpty())
        std::cout << "get is empty" << std::endl;
    if (gets.isEmpty())
        std::cout << "gets is empty" << std::endl;

    compoTest(data, get);
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

int main(int argc, char *argv[]) {
    Core::Orchestrator data;

    init(data);
    //    while (1) {
    // system call Proto:
    //  void SYS_NAME(Orchestrator &data);
    //}
    return 0;
}

int &converte_any(int *var) {
    *var = 4;
    return *var;
}

void test_ptr_to_ref() {
    int var = 5;
    std::cout << var << std::endl; // expected 5

    int &var2 = converte_any(&var);
    std::cout << var << std::endl;  // expected 4
    std::cout << var2 << std::endl; // expected 4
    var2 = 8;
    std::cout << var << std::endl;  // expected 8
    std::cout << var2 << std::endl; // expected 8
}
