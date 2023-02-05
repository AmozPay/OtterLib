#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include "Factory.hpp"
#include "registry.hpp"

#include <iostream>
#include <optional>
#include <string>

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
        Orchestrator(Otter::Core::Factory& fac) : _components(), _entity(), _builder(fac) {}

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
            register_facto<C>();
            return _components.register_component<C>();
        }

        template <class T>
        void register_abstract()
        {
            auto& tmp = _components.register_abstract<T>();
            return tmp;
        }

        template <buildable B>
        bool register_facto()
        {
            std::cout << "class << " << typeid(B).name() << " have buidler" << std::endl;
            _builder.addComponentSerializer(typeid(B).name(),
                                            std::function<void(Entity, Orchestrator&, pt::ptree)>(&B::__initialise));
            return true;
        }

        template <class T>
        bool register_facto()
        {
            std::cout << "class << " << typeid(T).name() << " no buildre" << std::endl;
            return false;
        }


      /**
       * @brief get_map_fromBase
       * @details a map with all the component with base of T
       * @params Template of type base
       * @return map of (index of component, pair(type_index, any)
       *
       */
        template <class T>
        std::unordered_map<std::size_t, std::pair<std::type_index, std::any&>>& get_map_fromBase()
        {
	  return _components.get_map_fromBase<T>();
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
        EntityManager _entity;
        Factory& _builder;
    };

} // namespace Otter::Core

#endif /* ORCHESTRATOR_H */
