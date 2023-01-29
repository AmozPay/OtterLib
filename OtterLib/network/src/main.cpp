/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** main
*/

#include "NetworkableClass.hpp"
#include "NetworkableVariable.hpp"
#include "Serializer.hpp"

class gps_position : public Network::Networkable::Class {
  public:
    gps_position(int d, int m, float s)
    {
        SET_NETWORKABLE_VARIABLE(degrees, d);
        SET_NETWORKABLE_VARIABLE(minutes, m);
        SET_NETWORKABLE_VARIABLE(seconds, s);
    };

    void setDegrees(int degrees) { this->degrees = this->degrees + degrees; }

    void setMinutes(int minutes) { this->minutes = this->minutes + minutes; }

    void setSeconds(float seconds) { this->seconds = seconds + seconds; }

  private:
    Network::Networkable::Variable<int> degrees;
    Network::Networkable::Variable<int> minutes;
    Network::Networkable::Variable<float> seconds;
};

int main()
{

    gps_position position(10, 10, 10);

    position.setDegrees(20);

    IdStringBufMap map = position.getUpdatedNetworkableVariable();

    // std::string id = "test";
    // std::string id2 = "test2";

    // Network::Networkable::Variable<int> var(12);
    // Network::Networkable::Variable<std::string> var2("test");
    // Network::Networkable::Class classNetworkable;

    // classNetworkable.setNewNetworkableVariable(id, var);
    // classNetworkable.setNewNetworkableVariable(id2, var2);

    // std::stringbuf bufferSent;

    // Network::Networkable::Variable<int> var3(42);

    // Network::Serializer::saveArchive(bufferSent, var3);

    // classNetworkable.updateNetworkableVariable(id, bufferSent);

    return 0;
}