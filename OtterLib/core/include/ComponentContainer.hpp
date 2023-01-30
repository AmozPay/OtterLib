#ifndef COMPONENTCONTAINER_H
#define COMPONENTCONTAINER_H

#include <any>
#include <functional>
#include <memory>
#include <optional>
#include <unordered_map>
#include <vector>

namespace Otter::Core {

    template <typename C>
    class lightArray {
      public:
        using size_type = size_t; /**< Unsigned integer type (usually std::size_t)*/
        using value_type = C;
        using container_t = std::vector<value_type>;
        using index_t = std::vector<size_type>;
        using reference_type = value_type&;             /**<value_type &*/
        using const_reference_type = value_type const&; /**<const value_type &*/

      public:
        lightArray() : _data(), _index(){};
        lightArray(lightArray const& source) : _data(source._data), _index(source._index){};
        lightArray(lightArray&& source) noexcept : _data(std::move(source._data)), _index(std::move(source._index)){};
        ~lightArray(){};

        reference_type operator[](size_t idx)
        {
            for (int i = 0; i != _index.size(); i++)
                if (_index[i] == idx)
                    return _data[i];
            return _data[idx];
        };

        const_reference_type operator[](size_t idx) const
        {
            for (int i = 0; i != _index.size(); i++)
                if (_index[i] == idx)
                    return _data[i];
            return _data[idx];
        }

        size_type size() const { return (_data.size()); }

        reference_type insert_at(size_type pos, C const& comp)
        {
            _data.push_back(comp);
            _index.push_back(pos);
            return _data.end();
        }

        reference_type insert_at(size_type pos, C&& comp)
        {
            _data.push_back(comp);
            _index.push_back(pos);
            return _data.end();
        }

        template <class... Params>
        reference_type emplace_at(size_type pos, Params&&... var)
        {
            _index.emplace_back(pos);
            return _data.emplace_back(var...);
        }

        bool isEmpty() const
        {
            if (_data.empty() == true)
                return true;
            return false;
        }

        void erase(size_type pos)
        {
            for (int i = 0; i != _index.size(); i++) {
                if (_index[i] == pos) {
                    _data.erase(_data.begin() + i);
                    _index.erase(_index.begin() + i);
                }
            }
        }

        size_type get_index(value_type const& obj) const
        {
            auto addr = std::addressof(obj);
            for (int i = 0; i != _data.size(); i++) {
                if (addr == std::addressof(_data[i]))
                    return (_index[i]);
            }
            return 0;
        }

      private:
        container_t _data;
        index_t _index;
    };

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

            if (_data[pos])
                alocator.destroy(&_data[pos]);
            alocator.construct(&_data[pos], var...);
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
        void erase(size_type pos) { _data[pos].reset(); }

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
