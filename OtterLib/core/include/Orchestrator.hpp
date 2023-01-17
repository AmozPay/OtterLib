#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include "registry.hpp"
#include <iostream>
#include <string>
class testcomponent {
  public:
    testcomponent(int var) {
        std::cout << "construct" << std::endl;
        this->dt = var;
    };
    ~testcomponent(){
        //      std::cout << "destruct test" << std::endl;
    };
    testcomponent(testcomponent const &source) { dt = source.dt; }
    testcomponent(testcomponent const &&source) noexcept { dt = std::move(source.dt); }

    testcomponent &operator=(testcomponent const other) {
        dt = other.dt;
        return *this;
    }
    testcomponent &operator=(testcomponent const &&source) noexcept {
        dt = std::move(source.dt);
        return *this;
    }
    void yolo() { std::cout << dt; }
    int getdata() { return dt; }

  private:
    int dt;
};

class test_str {
  public:
    test_str(int i, std::string toto = "") : name(toto) {
        _i = i;
        std::cout << "construct str" << std::endl;
    }
    ~test_str() {
        //  std::cout << "destruct" << std::endl;
    }

  private:
    int _i;
    std::string name;
};

namespace Core {
class Orchestrator {
  public:
    Orchestrator() : _components(), _entity() {}

    Entity createEntity() { return _entity.CreateEntity(); }

    template <class C> Core::sparse_array<C> &register_component() {
        return _components.register_component<C>();
    }
    template <class C> typename Core::ComponentManager::container_t<C> &get_components() {
        return _components.get_components<C>();
    }
    template <class C>
    typename Core::ComponentManager::container_t<C> const &get_components() const {
        return _components.get_components<C>();
    }
    template <typename C>
    typename Core::ComponentManager::reference_type<C> add_component(Entity const &addr,
                                                                     C &&component) {
        typename Core::ComponentManager::reference_type<C> re =
            _components.add_component<C>(addr, std::forward<C>(component));
        return re;
    }

    template <typename C, typename... Params>
    typename Core::ComponentManager::reference_type<C> emplace_component(Entity const &addr,
                                                                         Params &&...var) {
        return emplace_component<C>(addr, var...);
    }

    template <typename C> void remove_component(Entity const &addr) {
        _components.remove_component<C>(addr);
    }
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
