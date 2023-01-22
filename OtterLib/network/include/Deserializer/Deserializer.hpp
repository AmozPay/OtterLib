/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Deserializer
*/

#ifndef DESERIALIZER_HPP_
#define DESERIALIZER_HPP_

#include <sstream>

namespace Network {
    class Deserializer {
      public:
        Deserializer(){};
        ~Deserializer(){};

        template <class T>
        static T& loadArchive(std::stringbuf& stringBuff, T& loadedData)
        {
            boost::archive::binary_iarchive ia(stringBuff);

            ia >> loadedData;
            return loadedData;
        };
    };
} // namespace Network

#endif /* !DESERIALIZER_HPP_ */
