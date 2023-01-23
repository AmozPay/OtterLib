#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include "SystemManager.hpp"
#include "registry.hpp"

#include <iostream>
#include <string>

class testcomponent {
  public:
    testcomponent(int var)
    {
        std::cout << "construct" << std::endl;
        this->dt = var;
    };

    ~testcomponent(){
        //      std::cout << "destruct test" << std::endl;
    };

    testcomponent(testcomponent const& source) { dt = source.dt; }

    testcomponent(testcomponent const&& source) noexcept { dt = std::move(source.dt); }

    testcomponent& operator=(testcomponent const other)
    {
        dt = other.dt;
        return *this;
    }

    testcomponent& operator=(testcomponent const&& source) noexcept
    {
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
    test_str(int i, std::string toto = "") : name(toto)
    {
        _i = i;
        std::cout << "construct str" << std::endl;
    }

    ~test_str()
    {
        //  std::cout << "destruct" << std::endl;
    }

  private:
    int _i;
    std::string name;
};

namespace Otter::Core {

    /**
     * @class Orchestrator
     * @brief orchestre all the entity component and system together
     *
     * @details is the main interface for game dev, give righ to use all major partie of core
     *
     */
    class Orchestrator {
      public:
        /**
         * @brief Constructor default
         *
         * @details A basic constructor
         *
         */
        Orchestrator() : _components(), _entity() {}

        /**
         * @brief create a entity
         * @details Genere a Entity in the pool with a pool of object available
         * @return the Id of the entity generate
         */
        Entity createEntity() { return _entity.CreateEntity(); }

        /**
         * @brief Register component
         * @details register a component type in the core, do not initiate component data
         * @see sparse_array()
         * @return a reference to container_t<C> (aka: sparse_array<C>)
         */
        template <class C>
        Core::sparse_array<C>& register_component()
        {
            return _components.register_component<C>();
        }

        /**
         * @brief Get component
         * @details ask the core to give you the array of component C
         * @see sparse_array()
         * @return a reference to container_t<C> (aka: sparse_array<C)
         */
        template <class C>
        typename Core::ComponentManager::container_t<C>& get_components()
        {
            return _components.get_components<C>();
        }

        /**
         * @brief Get component
         * @see sparse_array()
         * @see get_components()
         * @return a Const reference to container_t<C> (aka: sparse_array)
         */
        template <class C>
        typename Core::ComponentManager::container_t<C> const& get_components() const
        {
            return _components.get_components<C>();
        }

        /**
         * @brief Add component
         * @details put a component, already exiten, in the core linked to a entity
         * @param The entity to link the component
         * @param a rvalue to a component
         * @see EntityManager()
         * @return a reference to the array of C component
         */
        template <typename C>
        typename Core::ComponentManager::reference_type<C> add_component(Entity const& addr, C&& component)
        {
            typename Core::ComponentManager::reference_type<C> re =
                _components.add_component<C>(addr, std::forward<C>(component));
            return re;
        }

        template <typename C, typename... Params>
        typename Core::ComponentManager::reference_type<C> emplace_component(Entity const& addr, Params&&... var)
        {
            return emplace_component<C>(addr, var...);
        }

        /**
         * @brief Remove a componet
         * @details remove a type componet from the entity
         * @param the entity who want to erase is component
         * @see EntityManager()
         * @return a reference to the array of C component
         */
        template <typename C>
        void remove_component(Entity const& addr)
        {
            _components.remove_component<C>(addr);
        }

        /**
         * @brief Remove entity
         * @details remove all component of a entity X, and remove the entity
         * @param entity to erase for the core
         */

        void remove_entity(Entity const& addr)
        {
            _components.remove_entity(addr);
            _entity.destroyEntity(addr);
        }

      private:
        ComponentManager _components;
        //	SystemManager _systems;
        EntityManager _entity;
    };

} // namespace Otter::Core

#endif /* ORCHESTRATOR_H */
