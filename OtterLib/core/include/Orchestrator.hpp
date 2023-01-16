#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include "registry.hpp"
#include <iostream>
class testcomponent{
  testcomponent(){
    std::cout << "construct" << std::endl;};
  void yolo(){std::cout << "oi";}
};


namespace Core {
class Orchestrator {
  public:
    Orchestrator() : _components(), _entity() {}

    Entity CreateEntity() { return _entity.CreateEntity(); }

  template <class C> Core::sparse_array<C> &register_component() {
        return _components.register_component<C>();
    }
  template <class C> typename Core::ComponentManager::container_t<C> &get_components() {
        return _components.get_components<C>();
    }
  template <class C> typename Core::ComponentManager::container_t<C> const &get_components() const {
        return _components.get_components<C>();
    }
    template <typename C>
    typename Core::ComponentManager::reference_type<C> add_component(Entity const &addr, C &&component) {
        return _components.add_component<C>(addr, component);
    }

    template <typename C, typename... Params>
    typename Core::ComponentManager::reference_type<C> emplace_component(Entity const &addr,
                                                                   Params &&...var) {
        return emplace_component<C>(addr, var...);
    }

    template <typename C> void remove_component(Entity const &addr) {}
    void remove_entity(Entity const &addr) {
        _components.remove_entity(addr);
        _entity.destroyEntity(addr);
    }

  private:
    ComponentManager _components;
    //    SystemManager _systems;
    EntityManager _entity;
};

} // namespace Core

#endif /* ORCHESTRATOR_H */
