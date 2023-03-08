/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibMouse.hpp
*/

#ifndef RAYLIBMOUSE_HPP_
#define RAYLIBMOUSE_HPP_

#include "Raylib.hpp"

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {
    /**
     * @brief The RaylibMouse class for Raylib mouse management
     */
    class RaylibMouse {
      public:
        /**
         * @brief Construct a new Mouse object
         * @param button: The button to check
         */
        explicit RaylibMouse(const int& button);
        /**
         * @brief Destroy the Mouse object
         */
        ~RaylibMouse();

        /**
         * @brief Set the button to check
         * @param button: The button to check
         * @return Nothing
         */
        void setButton(const int& button);

        /**
         * @brief Get the mouse wheel move
         * @return The mouse wheel move
         */
        static float getMouseWheelMove();
        /**
         * @brief Get the mouse X position
         * @return The mouse X position
         */
        static int getMouseX();
        /**
         * @brief Get the mouse Y position
         * @return The mouse Y position
         */
        static int getMouseY();
        /**
         * @brief Get the mouse position
         * @return The mouse position
         */
        static raylib::Vector2 getMousePosition();
        /**
         * @brief Get the mouse delta
         * @return The mouse delta
         */
        static raylib::Vector2 getMouseDelta();

        /**
         * @brief Check if the mouse button is pressed
         * @return True if the mouse button is pressed, false otherwise
         */
        [[nodiscard]] bool isMouseButtonPressed() const;
        /**
         * @brief Check if the mouse button is down
         * @return True if the mouse button is down, false otherwise
         */
        [[nodiscard]] bool isMouseButtonDown() const;
        /**
         * @brief Check if the mouse button is released
         * @return True if the mouse button is released, false otherwise
         */
        [[nodiscard]] bool isMouseButtonReleased() const;
        /**
         * @brief Check if the mouse button is up
         * @return True if the mouse button is up, false otherwise
         */
        [[nodiscard]] bool isMouseButtonUp() const;

      private:
        int _button;
    };
} // namespace Otter::Graphic::Raylib

#endif /* !RAYLIBMOUSE_HPP_ */