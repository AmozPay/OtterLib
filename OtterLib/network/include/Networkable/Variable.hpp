/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Networkable Variable
*/

#ifndef NETWORKABLEVARIABLE_HPP_
#define NETWORKABLEVARIABLE_HPP_

#include "Serializable.hpp"

using BinaryOutputArchive = boost::archive::binary_oarchive;
using BinaryInputArchive = boost::archive::binary_iarchive;

namespace Otter::Network::Networkable {
    enum class VariableStatusEnum { NOT_UPDATED, UPDATED };

    template <class T>
    class Variable : public Serializable {
        public:
        Variable() {}

        Variable(const T& newValue)
        {
            _value = newValue;
            _status = VariableStatusEnum::NOT_UPDATED;
        };

        ~Variable(){

        };

        T getValue() const { return _value; }

        VariableStatusEnum getStatus() const { return _status; };

        void operator=(const Variable<T>& newValue)
        {
            _value = newValue.getValue();
            if (newValue.getStatus() == VariableStatusEnum::UPDATED)
                return;
            _status = VariableStatusEnum::UPDATED;
        };

        void operator=(T& newValue)
        {
            _value = newValue;
            _status = VariableStatusEnum::UPDATED;
        };

        Variable<T> operator+(Variable<T> otherVariable) const
        {
            return Variable<T>(this->_value + otherVariable.getValue());
        };

        Variable<T> operator-(Variable<T> otherVariable) const
        {
            return Variable<T>(this->_value - otherVariable.getValue());
        };

        Variable<T> operator*(Variable<T> otherVariable) const
        {
            return Variable<T>(this->_value * otherVariable.getValue());
        };

        Variable<T> operator/(Variable<T> otherVariable) const
        {
            return Variable<T>(this->_value / otherVariable.getValue());
        };

        Variable<T> operator%(Variable<T> otherVariable) const
        {
            return Variable<T>(this->_value % otherVariable.getValue());
        };

        BinaryOutputArchive& operator&(BinaryOutputArchive& archive)
        {
            archive& _value;
            archive& _status;
            return archive;
        };

        BinaryInputArchive& operator&(BinaryInputArchive& archive)
        {
            archive& _value;
            archive& _status;
            return archive;
        };

        void resetStatus() { _status = VariableStatusEnum::NOT_UPDATED; };

        private:
        T _value;
        VariableStatusEnum _status;
    };
}

#endif /* !NETWORKABLEVARIABLE_HPP_ */
