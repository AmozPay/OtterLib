/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** main
*/

#include "Deserializer.hpp"
#include "Serializable.hpp"
#include "Serializer.hpp"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <sstream>

class gps_position : public Serializable {
  public:
    gps_position(){};
    gps_position(int d, int m, float s) : degrees(d), minutes(m), seconds(s){};

  private:
    boost::archive::binary_oarchive& operator&(boost::archive::binary_oarchive& archive)
    {
        archive& degrees;
        archive& minutes;
        archive& seconds;
        return archive;
    };

    boost::archive::binary_iarchive& operator&(boost::archive::binary_iarchive& archive)
    {
        archive& degrees;
        archive& minutes;
        archive& seconds;
        return archive;
    };

    int degrees;
    int minutes;
    float seconds;
};

int main()
{
    std::stringbuf stringBuff;
    std::stringbuf stringBuff2;

    const gps_position gps(0, 0, 0.0f);
    const gps_position gps2(1, 1, 1.f);

    Network::Serializer::saveArchive(stringBuff, gps);
    Network::Serializer::saveArchive(stringBuff2, gps2);

    gps_position newGps;
    gps_position newGps2;

    Network::Deserializer::loadArchive(stringBuff, newGps);
    Network::Deserializer::loadArchive(stringBuff2, newGps2);

    return 0;
}