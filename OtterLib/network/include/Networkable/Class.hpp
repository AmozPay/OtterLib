/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Networkable Class
*/

#ifndef NETWORKABLECLASS_HPP_
#define NETWORKABLECLASS_HPP_

#include "Deserializer.hpp"
#include "Serializer.hpp"
#include "Variable.hpp"

#include <any>
#include <functional>
#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <unordered_map>

using IdObjectMap = std::unordered_map<std::string, std::any>;
using IdStringBufMap = std::map<std::string, std::stringbuf&>;
using UpdateFunc = std::function<void(std::stringstream&, std::any&)>;
using UpdatedFunc = std::function<void(const std::string&, std::any&, std::stringstream&)>;
using UpdateAndUpdatedFuncPair = std::pair<UpdateFunc, UpdatedFunc>;
using IdUpdateAndUpdatedFuncMap = std::unordered_map<std::string, UpdateAndUpdatedFuncPair>;

#define SET_NETWORKABLE_VARIABLE(newtworkVariable, value)                                                              \
    {                                                                                                                  \
        newtworkVariable = value;                                                                                      \
        this->setNewNetworkableVariable<decltype(value)>(#newtworkVariable, newtworkVariable);                         \
    }

namespace Otter::Network::Networkable {
    class Class {
        public:
        Class(){};
        ~Class(){};

        void updateNetworkableVariables(std::stringstream& stream)
        {
            std::stringstream::pos_type endStreamPos = stream.tellp();
            std::string id;

            while (stream.tellg() < endStreamPos) {
                id = Deserializer::loadArchive<std::string>(stream);
                updateNetworkableVariable(id, stream);
            }
        }

        std::optional<std::stringstream> getUpdatedNetworkableVariable(const std::size_t& componentId)
        {
            std::stringstream stream;
            std::stringstream::pos_type streamWriteBegin;
            IdUpdateAndUpdatedFuncMap::iterator it;

            Serializer::saveArchive(stream, componentId);
            streamWriteBegin = stream.tellp();
            for (auto& [key, value] : _idObjectMap) {
                it = _idUpdateAndUpdatedFuncMap.find(key);
                if (it == _idUpdateAndUpdatedFuncMap.end())
                    break;
                it->second.second(key, value, stream);
            }
            if (streamWriteBegin == stream.tellp())
                return std::nullopt;
            return stream;
        }

        protected:
        template <class T>
        void setNewNetworkableVariable(std::string id, Variable<T>& variable)
        {
            std::any value = std::make_any<Variable<T>*>(&variable);

            UpdateFunc updateFunc = [](std::stringstream& stream, std::any object)
            {
                Variable<T>* networkVariable = std::any_cast<Variable<T>*>(object);

                *networkVariable = Network::Deserializer::loadArchive<Variable<T>>(stream);
                networkVariable->resetStatus();
            };

            UpdatedFunc updatedFunc = [](const std::string& id, std::any& object, std::stringstream& stream)
            {
                Variable<T>* networkVariable = std::any_cast<Variable<T>*>(object);

                if (networkVariable->getStatus() == VariableStatusEnum::UPDATED) {
                    Network::Serializer::saveArchive<std::string>(stream, id);
                    Network::Serializer::saveArchive<Variable<T>>(stream, *networkVariable);
                    networkVariable->resetStatus();
                }
            };
            _idObjectMap.insert({id, value});
            _idUpdateAndUpdatedFuncMap.try_emplace(id, std::pair<UpdateFunc, UpdatedFunc>(updateFunc, updatedFunc));
        };

        private:
        void updateNetworkableVariable(const std::string& id, std::stringstream& stream)
        {
            IdObjectMap::iterator idObjectIt = _idObjectMap.find(id);
            IdUpdateAndUpdatedFuncMap::iterator updateFuncIt = _idUpdateAndUpdatedFuncMap.find(id);

            if (idObjectIt == _idObjectMap.end() || updateFuncIt == _idUpdateAndUpdatedFuncMap.end()) {
                return;
            }
            updateFuncIt->second.first(stream, idObjectIt->second);
        };

        IdObjectMap _idObjectMap;
        IdUpdateAndUpdatedFuncMap _idUpdateAndUpdatedFuncMap;
    };
}

#endif /* !NETWORKABLECLASS_HPP_ */
