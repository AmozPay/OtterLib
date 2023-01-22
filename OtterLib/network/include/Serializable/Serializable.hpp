/*
** EPITECH PROJECT, 2023
** network [WSL: Ubuntu]
** File description:
** Serializable
*/

#ifndef SERIALIZABLE_HPP_
#define SERIALIZABLE_HPP_

#include <boost/serialization/access.hpp>

class Serializable {
  public:
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version);

  protected:
    friend class boost::serialization::access;
};

#endif /* !SERIALIZABLE_HPP_ */
