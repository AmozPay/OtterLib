/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Deserializer
*/

#include "Deserializer.hpp"

namespace Network {
    Deserializer::Deserializer() { id = 0; };

    Deserializer::~Deserializer(){};

    void Deserializer::addNewElementToDeserialize(const std::type_index& typeIndex,
                                                  const DeserializeFunction& deserializeFunction)
    {
        typeIndexAndIdMap.insert({typeIndex, id});
        idAndDeserializeFunctionMap.insert({id, deserializeFunction});
    }

    std::size_t Deserializer::getIdOfTypeIndex(const std::type_index& typeIndex) const
    {
        return typeIndexAndIdMap.find(typeIndex)->second;
    }

    void Deserializer::deserializeElement(std::size_t& id, std::stringbuf& stringBuff)
    {
        idAndDeserializeFunctionMap.find(id)->second(stringBuff);
    }
} // namespace Network
