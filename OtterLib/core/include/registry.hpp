
#ifndef REGISTRY_H
#define REGISTRY_H

#include "ComponentContainer.hpp"
#include "EntityManager.hpp"

#include <any>
#include <functional>
#include <memory>
#include <optional>
#include <typeindex>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Otter::Core {

    class ComponentManager {
      public:
        template <class C>
        using container_t = sparse_array<C>;
        template <class C>
        using yagami = lightArray<C>;

        template <class C>
        using reference_type = typename container_t<C>::reference_type;

      public:
        ComponentManager(){};
        ~ComponentManager(){};

        /*************************************Imuable compund**********************************************/
        template <class C>
        yagami<C>& register_imuable() // requires (std::is_default_constructible_v<C>)
        {
            auto result = _imuable_map.try_emplace(std::type_index(typeid(C)), std::make_any<lightArray<C>>());
            if (result.second == true) {
                _destroy_map.emplace(std::type_index(typeid(C)), [](ComponentManager& m, Entity const& entity)
                                     { m.get_imuable<C>().erase(entity); });
            }
            yagami<C>* test = std::any_cast<yagami<C>>(&(_imuable_map[std::type_index(typeid(C))]));
            return *test;
        }

        template <class C>
        yagami<C>& get_imuable()
        {
            return *(std::any_cast<yagami<C>>(&(_imuable_map[std::type_index(typeid(C))])));
        }

        template <class C>
        yagami<C> const& get_imuable() const
        {
            return *(std::any_cast<yagami<C>>(&(*_imuable_map.find(std::type_index(typeid(C))))));
        }

        template <typename C>
        typename lightArray<C>::reference_type add_imuable(Entity const& addr, C&& component)
        {
            yagami<C>& cont = this->get_imuable<C>();

            C& tmp = cont.insert_at(addr, component);
            return tmp;
        }

        template <typename C, typename... Params>
        typename lightArray<C>::reference_type emplace_imuable(Entity const& addr, Params&&... var)
        {
            yagami<C>& cont = *_imuable_map.find(std::type_index(typeid(C)));
            return cont.emplace_at(addr, var...);
        }

        template <typename C>
        void remove_imuable(Entity const& addr)
        {
            yagami<C>& cont = this->get_imuable<C>();
            cont.erase(addr);
        }

        ////////////////////////////////////////////////   base component

        template <class C>
        container_t<C>& register_component() // requires (std::is_default_constructible_v<C>)
        {
            auto result = _type_map.try_emplace(std::type_index(typeid(C)), std::make_any<sparse_array<C>>());
            if (result.second == true) {
                _destroy_map.emplace(std::type_index(typeid(C)), [](ComponentManager& m, Entity const& entity)
                                     { m.get_components<C>().erase(entity); });
            }
            container_t<C>* test = std::any_cast<container_t<C>>(&(_type_map[std::type_index(typeid(C))]));
            return *test;
        }

        template <class C>
        container_t<C>& get_components()
        {
            return *(std::any_cast<container_t<C>>(&(_type_map[std::type_index(typeid(C))])));
        }

        template <class C>
        container_t<C> const& get_components() const
        {
            return *(std::any_cast<container_t<C>>(&(*_type_map.find(std::type_index(typeid(C))))));
        }

        template <typename C>
        reference_type<C> add_component(Entity const& addr, C&& component)
        {
            container_t<C>& cont = this->get_components<C>();

            std::optional<C>& tmp = cont.insert_at(addr, component);
            return tmp;
        }

        template <typename C, typename... Params>
        reference_type<C> emplace_component(Entity const& addr, Params&&... var)
        {
            container_t<C>& cont = *_type_map.find(std::type_index(typeid(C)));
            return cont.emplace_at(addr, var...);
        }

        // template <typename C> void remove_component() { rm a full components list

        template <typename C>
        void remove_component(Entity const& addr)
        {
            container_t<C>& cont = this->get_components<C>();
            cont.erase(addr);
        }

        void remove_entity(Entity const& addr)
        {
            for (const auto& [key, value] : _destroy_map) {
                value(*this, addr);
            }
        }

      private:
        std::unordered_map<std::type_index, std::any> _type_map; // std::any_cast
        std::unordered_map<std::type_index, std::function<void(ComponentManager&, Entity const&)>> _destroy_map;
        std::unordered_map<std::type_index, std::any> _imuable_map;
    };
} // namespace Otter::Core
#endif /*COMPONENTMANAGER_H */
