
#ifndef REGISTRY_H
#define REGISTRY_H

#include "EntityManager.hpp"
#include <any>
#include <functional>
#include <memory>
#include <optional>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace Core {
template <typename C> class sparse_array {
  public:
    using value_type = std::optional<C>;         // optional component type
    using container_t = std::vector<value_type>; // optionally add your allocator template here .

    using reference_type = value_type &;
    using const_reference_type = value_type const &;

    using size_type = typename container_t::size_type;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;
    using allocator_type = typename container_t::allocator_type;

  public:
    sparse_array() : _data(){}; // You can add more constructors .
    sparse_array(sparse_array const &source) : _data(source._data){};
    sparse_array(sparse_array &&source) noexcept
        : _data(std::move(source._data)){}; // move constructor
    ~sparse_array(){};

    sparse_array &operator=(sparse_array const &other) {
        _data = other._data;
    }; // copy assignment operator

    sparse_array &operator=(sparse_array &&other) noexcept {
        _data = std::move(other._data);
    }; // move assignment operator

    reference_type operator[](size_t idx) { return _data[idx]; };
    const_reference_type operator[](size_t idx) const { return _data[idx]; }

    iterator begin() { return _data.begin(); };
    const_iterator begin() const { return _data.begin(); }
    const_iterator cbegin() const { return _data.cbegin(); }

    iterator end() { return _data.end(); };
    const_iterator end() const { return _data.end; };
    const_iterator cend() const { return _data.cend; };

    size_type size() const { return (_data.size()); }

    reference_type insert_at(size_type pos, C const &comp) {
        if (pos >= _data.size())
            _data.resize(pos);
        _data[pos] = comp;
        return _data[pos];
    }
    reference_type insert_at(size_type pos, C &&comp) {
        if (pos >= _data.size()) {
            _data.resize(pos);
        }
        _data[pos] = comp;
        return _data[pos];
    }

    // to test maybe not work   don't understnad use of std::allocator_trait
    template <class... Params> reference_type emplace_at(size_type pos, Params &&...var) {
        std::allocator<std::optional<C>> alocator = _data.get_allocator();

        if (_data[pos])
            alocator.destroy(&_data[pos]);
        alocator.construct(&_data[pos], var...);
        return _data[pos];
    }

    void erase(size_type pos) { _data[pos].reset(); }
    size_type get_index(value_type const &obj) const {
        auto addr = std::addressof(obj);
        for (int i = 0; i != _data.size(); i++) {
            if (addr == std::addressof(_data[i]))
                return (i);
        }
        return 0;
    }

  private:
    container_t _data;
};

class ComponentManager {
  public:
    template <class C> using container_t = sparse_array<C>;
    template <class C> using reference_type = typename container_t<C>::reference_type;

  public:
    ComponentManager(){};

    template <class C> container_t<C> &register_component() {
        auto res =
            _type_map.try_emplace(std::type_index(typeid(C), std::make_any<sparse_array<C>>()));
        if (res.second == true) {
            _destroy_map.emplace(
                std::type_index(typeid(C), [](ComponentManager &m, Entity const &entity) {
                    auto type = m.get_components<C>().erase(entity);
                }));

            return (std::any_cast<C>(*res.first));
        }
        return std::any_cast<C>(*_type_map.find(std::type_index(typeid(C))));
    }

    template <class C> container_t<C> &get_components() {
        return std::any_cast<C>(*_type_map.find(std::type_index(typeid(C))));
    }

    template <class C> container_t<C> const &get_components() const {
        return std::any_cast<C>(*_type_map.find(std::type_index(typeid(C))));
    }

    template <typename C> reference_type<C> add_component(Entity const &addr, C &&component) {
        container_t<C> cont = *_type_map.find(std::type_index(typeid(C)));
        return cont.insert_at(addr, component);
    }

    template <typename C, typename... Params>
    reference_type<C> emplace_component(Entity const &addr, Params &&...var) {
        container_t<C> cont = *_type_map.find(std::type_index(typeid(C)));
        return cont.emplace_at(addr, var...);
    }
    template <typename C> void remove_component(Entity const &addr) {
        container_t<C> cont = *_type_map.find(std::type_index(typeid(C)));
        cont.erase(addr);
    }

    void remoce_entity(Entity const &addr) {
        for (const auto &[key, value] : _destroy_map) {
            value(*this, addr);
        }
    }

  private:
    std::unordered_map<std::type_index, std::any> _type_map; // std::any_cast
    std::unordered_map<std::type_index, std::function<void(ComponentManager &, Entity const &)>>
        _destroy_map;
};
} // namespace Core
#endif /*COMPONENTMANAGER_H */
