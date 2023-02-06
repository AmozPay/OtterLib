/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Utils.hpp
*/

#ifndef RTYPE_UTILS_HPP
#define RTYPE_UTILS_HPP

namespace Otter::Games::RType::Utils {

    /**
     * @brief Struct for the vector2
     * @details The vector2 is used to store a 2D vector (float)
     * @struct Vector2
     * @var x: The x value of the vector
     * @var y: The y value of the vector
     */
    struct Vector2 {
        float x;
        float y;
    };

    enum EventState { FORWARD, BACKWARD, UP, DOWN, CLOSE, SHOOT };

} // namespace Otter::Games::RType::Utils

#endif // RTYPE_UTILS_HPP