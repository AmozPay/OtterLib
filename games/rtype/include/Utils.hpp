/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Utils.hpp
*/

#ifndef RTYPE_UTILS_HPP
#define RTYPE_UTILS_HPP

#include "Serializable.hpp"

namespace Otter::Games::RType::Utils {

    /**
     * @brief Struct for the vector2
     * @details The vector2 is used to store a 2D vector (float)
     * @struct Vector2
     * @var x: The x value of the vector
     * @var y: The y value of the vector
     */
    struct Vector2: public Otter::Network::Serializable {
        float x;
        float y;

        Vector2() {};

        Vector2(int x, int y) {
            this->x = x;
            this->y = y;
        };

        boost::archive::binary_oarchive& operator&(
            boost::archive::binary_oarchive& archive
        ) {
            archive & x;
            archive & y;
            return archive;
        }

        boost::archive::binary_iarchive& operator&(
            boost::archive::binary_iarchive& archive
        ) {
            archive & x;
            archive & y;
            return archive;
        }
    };

    /**
     * @brief Struct for the rectangle
     * @details The rectangle is used to store a 2D rectangle (float)
     * @struct Rectangle
     * @var x: The x value of the rectangle
     * @var y: The y value of the rectangle
     * @var width: The width value of the rectangle
     * @var height: The height value of the rectangle
     */
    struct Rectangle {
        float x;
        float y;
        float width;
        float height;
    };

    enum EventState { FORWARD, BACKWARD, UP, DOWN, CLOSE, SHOOT };
} // namespace Otter::Games::RType::Utils

#endif // RTYPE_UTILS_HPP
