#ifndef COMPONENTCONTAINER_H
#define COMPONENTCONTAINER_H

#include <any>
#include <functional>
#include <memory>
#include <optional>
#include <unordered_map>
#include <vector>

namespace Otter::Core {

    /**
     * @class sparse_array
     * @brief Container type for any unique typename
     *
     */
    template <typename C>
    class sparse_array {
      public:
        using value_type = std::optional<C>;         /**<optional component of C*/
        using container_t = std::vector<value_type>; /**<Vector of value_type*/

        using reference_type = value_type&;             /**<value_type &*/
        using const_reference_type = value_type const&; /**<const value_type &*/

        using size_type = typename container_t::size_type; /**< Unsigned integer type (usually std::size_t)*/
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;
        using allocator_type = typename container_t::allocator_type;

      public:
        /**
         * @brief Constructor default
         */
        sparse_array() : _data(){};

        /**
         * @brief Constructor by copy
         *
         * @details create a new class and copy the data from the source in the newly created
         *
         * @param lvalue to a sparse array
         */
        sparse_array(sparse_array const& source) : _data(source._data){};

        /**
         * @brief Constructor move
         *
         * @details Move a existing sparse array to the one created
         *
         * @param A Rvalue to a sparse array
         * @warning Methode used for optimization
         */
        sparse_array(sparse_array&& source) noexcept : _data(std::move(source._data)){}; // move constructor
        ~sparse_array(){};

        /**
         * @brief Operator for copy
         * @details copy the data from other
         */
        sparse_array& operator=(sparse_array const& other)
        {
            if (this == &other)
                return *this;
            _data = other._data;
            return *this;
        };

        /**
         * @brief Operator for move
         * @details move the data from other
         */
        sparse_array& operator=(sparse_array&& other) noexcept
        {
            _data = std::move(other._data);
            return *this;
        };

        /**
         * @brief Operator for indexing
         * @param size_t of the data scearched
         * @return reference_type
         */
        reference_type operator[](size_t idx) { return _data[idx]; };

        /**
         * @brief Operator for indexing
         * @param size_t of the data scearched
         * @return const_reference_type
         */
        const_reference_type operator[](size_t idx) const { return _data[idx]; }

        iterator begin() { return _data.begin(); };

        const_iterator begin() const { return _data.begin(); }

        const_iterator cbegin() const { return _data.cbegin(); }

        iterator end() { return _data.end(); };

        const_iterator end() const { return _data.end; };

        const_iterator cend() const { return _data.cend; };

        /**
         * @brief Size
         * @return nomber of element stored
         */
        size_type size() const { return (_data.size()); }

        /**
         * @brief Insert data a index
         * @param index
         * @param lvalue of Composant to store
         * @return reference_type
         */
        reference_type insert_at(size_type pos, C const& comp)
        {
            if (pos >= _data.size())
                _data.resize(pos, std::optional<C>());
            _data.insert(_data.begin() + pos, comp);
            return _data[pos];
        }

        /**
         * @brief Insert data a index
         * @param index
         * @param rvalue of Composant to store
         * @return reference_type
         */
        reference_type insert_at(size_type pos, C&& comp)
        {
            if (pos >= _data.size())
                _data.resize(pos, std::optional<C>());
            _data.insert(_data.begin() + pos, comp);
            return _data[pos];
        }

        // to test maybe not work   don't understnad use of std::allocator_trait
        template <class... Params>
        reference_type emplace_at(size_type pos, Params&&... var)
        {
            std::allocator<std::optional<C>> alocator = _data.get_allocator();
            /*
            if (_data[pos])
                alocator.destroy(&_data[pos]);
            alocator.construct(&_data[pos], var...);
            */
            return _data[pos];
        }

        /**
         * @brief test if container empty
         * @return return true if empty
         */
        bool isEmpty() const
        {
            if (_data.empty() == true)
                return true;
            return false;
        }

        /**
         * @brief erase data at index
         * @param index
         */
        void erase(size_type pos)
        {
            if (_data.size() <= pos)
                return;
            if (_data[pos])
                _data[pos].reset();
        }

        /**
         * @brief find index of component
         * @param Valu_type of a component
         * @return index at wich is store
         */
        size_type get_index(value_type const& obj) const
        {
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
} // namespace Otter::Core

#endif /* COMPONENTCONTAINER_H */
