
#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H
#include "registry.hpp"
namespace Core {
class orchestrator {
  public:
    orchestrator() : _components(), _entity() {}

    Entity CreateEntity();

    template <class C> container_t<C> &register_component() {}
    // template <class C> container_t<C> &get_components() {}
    //   template <class C> container_t<C> const &get_components() const {}
    // template <typename C>
    // eference_type<C> add_component(Entity const &addr, C &&component) {}

    // template <typename C, typename... Params>
    //  reference_type<C> emplace_component(Entity const &addr, Params &&...var) {}

    //    template <typename C> void remove_component(Entity const &addr) {}
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
