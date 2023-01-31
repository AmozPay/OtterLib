/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Serializable
*/

#ifndef SERIALIZABLE_HPP_
#define SERIALIZABLE_HPP_

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/access.hpp>

class Serializable {
  public:
    virtual ~Serializable() = default;

  private:
    virtual boost::archive::binary_oarchive& operator&(boost::archive::binary_oarchive& archive) = 0;
    virtual boost::archive::binary_iarchive& operator&(boost::archive::binary_iarchive& archive) = 0;

    void serialize(boost::archive::binary_oarchive& binaryOutputArchive, const unsigned int)
    {
        *this& binaryOutputArchive;
    };

    void serialize(boost::archive::binary_iarchive& binaryInputArchive, const unsigned int)
    {
        *this& binaryInputArchive;
    };

    friend class boost::serialization::access;
};

#endif /* !SERIALIZABLE_HPP_ */
