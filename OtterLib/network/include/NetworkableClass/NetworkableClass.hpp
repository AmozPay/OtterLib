/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** NetworkableClass
*/

#ifndef NETWORKABLECLASS_HPP_
#define NETWORKABLECLASS_HPP_

#include "Deserializer.hpp"
#include "Serializer.hpp"

#include <any>
#include <functional>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using IdObjectMap = std::unordered_map<std::string, std::any>;
using IdStringBufMap = std::map<std::string, std::stringbuf&>;
using UpdateFunc = std::function<void(std::stringbuf&, std::any&)>;
using UpdatedFunc = std::function<void(const std::string&, std::any&, IdStringBufMap&)>;
using UpdateAndUpdatedFuncPair = std::pair<UpdateFunc, UpdatedFunc>;
using IdUpdateAndUpdatedFuncMap = std::unordered_map<std::string, UpdateAndUpdatedFuncPair>;

#define SET_NETWORKABLE_VARIABLE(newtworkVariable, value)                                                              \
    {                                                                                                                  \
        newtworkVariable = value;                                                                                      \
        this->setNewNetworkableVariable<decltype(value)>(#newtworkVariable, newtworkVariable);                         \
    }

namespace Network {
    namespace Networkable {
        class Class {
          public:
            Class(){};
            ~Class(){};

            void updateNetworkableVariables(IdStringBufMap& variablesToUpdate)
            {
                for (auto& [key, value] : variablesToUpdate) {
                    updateNetworkableVariable(key, value);
                }
            }

            IdStringBufMap getUpdatedNetworkableVariable()
            {
                IdStringBufMap variablesToUpdate;

                for (auto& [key, value] : _idObjectMap) {
                    _idUpdateAndUpdatedFuncMap.find(key)->second.second(key, value, variablesToUpdate);
                }
                return variablesToUpdate;
            }

          protected:
            template <class T>
            void setNewNetworkableVariable(std::string id, Variable<T>& variable)
            {
                std::any value = std::make_any<Variable<T>*>(&variable);

                UpdateFunc updateFunc = [](std::stringbuf& stringBuff, std::any object)
                {
                    Variable<T>* networkVariable = std::any_cast<Variable<T>*>(object);

                    *networkVariable = Network::Deserializer::loadArchive<Variable<T>>(stringBuff);
                    networkVariable->resetStatus();
                };

                UpdatedFunc updatedFunc = [](const std::string& id, std::any& object, IdStringBufMap& variablesToUpdate)
                {
                    Variable<T>* networkVariable = std::any_cast<Variable<T>*>(object);

                    if (networkVariable->getStatus() == VariableStatusEnum::UPDATED) {
                        std::stringbuf stringBuff;

                        Network::Serializer::saveArchive<Variable<T>>(stringBuff, *networkVariable);
                        variablesToUpdate.insert(std::pair<std::string, std::stringbuf&>(id, stringBuff));
                    }
                };

                _idObjectMap.insert({id, value});
                _idUpdateAndUpdatedFuncMap.try_emplace(id, std::pair<UpdateFunc, UpdatedFunc>(updateFunc, updatedFunc));
            };

          private:
            void updateNetworkableVariable(const std::string& id, std::stringbuf& stringBuff)
            {
                std::any& variableNetworkable = _idObjectMap.find(id)->second;

                _idUpdateAndUpdatedFuncMap.find(id)->second.first(stringBuff, variableNetworkable);
            };

            IdObjectMap _idObjectMap;
            IdUpdateAndUpdatedFuncMap _idUpdateAndUpdatedFuncMap;
        };
    } // namespace Networkable
} // namespace Network

#endif /* !NETWORKABLECLASS_HPP_ */
