/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** NetworkableVariable
*/

#ifndef NETWORKABLEVARIABLE_HPP_
#define NETWORKABLEVARIABLE_HPP_

#include "Serializable.hpp"

using BinaryOutputArchive = boost::archive::binary_oarchive;
using BinaryInputArchive = boost::archive::binary_iarchive;

namespace Network {
    namespace Networkable {
        enum class VariableStatusEnum { NOT_UPDATED, UPDATED };

        template <class T>
        class Variable : public Serializable {
          public:
            Variable() {}

            Variable(const T& newValue)
            {
                value = newValue;
                status = VariableStatusEnum::NOT_UPDATED;
            };

            ~Variable(){

            };

            T getValue() const { return value; }

            VariableStatusEnum getStatus() const { return status; };

            void operator=(const Variable<T>& newValue)
            {
                value = newValue.getValue();
                if (newValue.getStatus() == VariableStatusEnum::UPDATED)
                    return;
                status = VariableStatusEnum::UPDATED;
            };

            void operator=(T& newValue)
            {
                value = newValue;
                status = VariableStatusEnum::UPDATED;
            };

            BinaryOutputArchive& operator&(BinaryOutputArchive& archive)
            {
                archive& value;
                archive& status;
                return archive;
            };

            BinaryInputArchive& operator&(BinaryInputArchive& archive)
            {
                archive& value;
                archive& status;
                return archive;
            };

            void resetStatus() { status = VariableStatusEnum::NOT_UPDATED; };

          private:
            T value;
            VariableStatusEnum status;
        };
    } // namespace Networkable
} // namespace Network

#endif /* !NETWORKABLEVARIABLE_HPP_ */
