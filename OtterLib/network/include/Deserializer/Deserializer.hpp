/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Deserializer
*/

#ifndef DESERIALIZER_HPP_
#define DESERIALIZER_HPP_

#include <boost/archive/binary_iarchive.hpp>
#include <sstream>

namespace Network {
    class Deserializer {
      public:
        Deserializer(){};
        ~Deserializer(){};

        template <class T>
        static T loadArchive(std::stringstream& stringStream)
        {
            T loadedData = T();
            boost::archive::binary_iarchive ia(stringStream);

            ia >> loadedData;
            return loadedData;
        };
    };
} // namespace Network

#endif /* !DESERIALIZER_HPP_ */
