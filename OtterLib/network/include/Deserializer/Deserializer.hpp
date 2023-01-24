/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Deserializer
*/

#ifndef DESERIALIZER_HPP_
#define DESERIALIZER_HPP_

#include <boost/archive/binary_iarchive.hpp>
#include <functional>
#include <sstream>
#include <tuple>
#include <typeindex>
#include <unordered_map>

using TypeIndexAndIdMap = std::unordered_map<std::type_index, std::size_t>;
using DeserializeFunction = std::function<void(std::stringbuf&)>;
using IdAndDeserializeFunctionMap = std::unordered_map<std::size_t, DeserializeFunction>;

namespace Network {
    class Deserializer {
      public:
        Deserializer();
        ~Deserializer();
        void addNewElementToDeserialize(const std::type_index& typeIndex,
                                        const DeserializeFunction& deserializeFunction);
        std::size_t getIdOfTypeIndex(const std::type_index& typeIndex) const;
        void deserializeElement(std::size_t& id, std::stringbuf& stringBuff);

        template <class T>
        static T loadArchive(std::stringbuf& stringBuff)
        {
            T loadedData = T();
            boost::archive::binary_iarchive ia(stringBuff);

            ia >> loadedData;
            return loadedData;
        };

      private:
        TypeIndexAndIdMap typeIndexAndIdMap;
        IdAndDeserializeFunctionMap idAndDeserializeFunctionMap;
        std::size_t id;
    };
} // namespace Network

#endif /* !DESERIALIZER_HPP_ */
