/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Utils.hpp
*/

#pragma once
namespace Otter::Core::Utils {

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
