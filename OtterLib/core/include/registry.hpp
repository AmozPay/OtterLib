

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
        using reference_type = typename container_t<C>::reference_type;

      public:
        ComponentManager(){};

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
      /*
        template <class T>
        void register_abstract()
        {
            _index_map.try_emplace(std::type_index(typeid(T)),
                                   std::unordered_map<std::size_t, std::pair<std::type_index, std::any&>>());

            for (auto& [Key, Value] : _type_map) {
                auto op2.t = testHeritance<T>(Value);
                if (opt.has_value()) {
                    auto& map = _index_map[std::type_index(typeid(T))];
                    map.insert({map.size() + 1, {Key, Value}});
                }
            }
        }

        template <class T>
        std::optional<container_t<T>> testHeritance(const std::any& arr)
        {
            if (const container_t<T>* v = std::any_cast<container_t<T>>(&arr))
                return std::optional<container_t<T>>(*v);
            else
                return std::nullopt;
        }

        template <class C, class T>
        void register_type_id()
        {
            auto& map = _index_map[std::type_index(typeid(T))];
            map.insert({map.size() + 1, {std::type_index(typeid(C)), _type_map[std::type_index(typeid(C))]}});
        }*/

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
            container_t<C> cont = *_type_map.find(std::type_index(typeid(C)));
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
      /*     template <class T>
        std::unordered_map<std::size_t, std::pair<std::type_index, std::any&>>& get_map_fromBase()
        {

	  return _index_map[std::type_index(typeid(T))];
	  }*/
      template<class T>
      std::size_t get_componentIndex()
      {
	for (size_t i =0; _componentIndex.size() > i ; i++)
	  {
	    if (std::type_index(typeid(T)) == _componentIndex[i])
	      return i;
          }
	return 0;
      }
      /*      std::type_index get_componentType_index(std::size_t index)
      {

      }*/
      
      private:
        std::unordered_map<std::type_index, std::any> _type_map; // std::any_cast
        std::unordered_map<std::type_index, std::function<void(ComponentManager&, Entity const&)>> _destroy_map;

        std::vector<std::type_index> _componentIndex;

      //std::unordered_map<std::type_index, std::unordered_map<std::size_t, std::pair<std::type_index, std::any&>>>  _index_map;
    };
} // namespace Otter::Core
#endif /*COMPONENTMANAGER_H */
