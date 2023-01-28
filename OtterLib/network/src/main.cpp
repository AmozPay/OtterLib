/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** main
*/

#include "Deserializer.hpp"
#include "Serializer.hpp"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <iostream>
#include <sstream>
#include <typeinfo>

class gps_position {
  public:
    gps_position(){};
    gps_position(int d, int m, float s) : degrees(d), minutes(m), seconds(s){};

  private:
    int degrees;
    int minutes;
    float seconds;
};

#include "NetworkableVariable.hpp"

int main()
{
    Network::Networkable::Variable<int> var(12);

    var = 42;

    std::stringbuf stringBuff;

    Network::Serializer::saveArchive(stringBuff, var);

    auto newVar = Network::Deserializer::loadArchive<Network::Networkable::Variable<int>>(stringBuff);

    return 0;
}