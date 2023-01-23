/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Serializer
*/

#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <boost/archive/binary_oarchive.hpp>
#include <sstream>

namespace Network {
    class Serializer {
      public:
        Serializer(){};
        ~Serializer(){};

        template <class T>
        static void saveArchive(std::stringbuf& stringBuff, T classToArchive)
        {
            boost::archive::binary_oarchive oa(stringBuff);

            oa << classToArchive;
        };
    };
} // namespace Network

#endif /* !SERIALIZER_HPP_ */
