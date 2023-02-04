/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibKeyboard.hpp
*/

#ifndef RAYLIBKEYBOARD_HPP_
#define RAYLIBKEYBOARD_HPP_

#include "Raylib.hpp"

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {
    /**
     * @brief The RaylibKeyboard class for Raylib keyboard management
     */
    class RaylibKeyboard {
      public:
        /**
         * @brief Construct a new Keyboard object
         * @param key: The key to check
         */
        explicit RaylibKeyboard(const int& key);
        /**
         * @brief Destroy the Keyboard object
         */
        ~RaylibKeyboard();

        enum RaylibKey {
            LEFT = KEY_LEFT,
            RIGHT = KEY_RIGHT,
            UP = KEY_UP,
            DOWN = KEY_DOWN,
            SPACE = KEY_SPACE,
            ESCAPE = KEY_ESCAPE
        };

        /**
         * @brief Set the key to check
         * @param key: The key to check
         * @return Nothing
         */
        void setKey(const int& key);
        /**
         * @brief Set the exit key
         * @return Nothing
         */
        void setExitKey() const;

        /**
         * @brief Check if a key has been pressed once
         * @return True if the key is pressed, false otherwise
         */
        [[nodiscard]] bool isKeyPressed() const;
        /**
         * @brief Check if a key is being pressed
         * @return True if the key is down, false otherwise
         */
        [[nodiscard]] bool isKeyDown() const;
        /**
         * @brief Check if a key has been released once
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyReleased() const;
        /**
         * @brief Check if a key is NOT being pressed
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyUp() const;
        /**
         * @brief Get key pressed (keycode)
         * @details Call it multiple times for keys queued
         * @return The keycode of the key pressed, 0 if the queue is empty
         */
        static int getKeyPressed();

      private:
        int _key;
    };
} // namespace Otter::Graphic::Raylib

#endif /* !RAYLIBKEYBOARD_HPP_ */