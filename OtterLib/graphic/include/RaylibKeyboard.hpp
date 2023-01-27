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
         * @brief Check if the key is pressed
         * @return True if the key is pressed, false otherwise
         */
        [[nodiscard]] bool isKeyPressed() const;
        /**
         * @brief Check if the key is down
         * @return True if the key is down, false otherwise
         */
        [[nodiscard]] bool isKeyDown() const;
        /**
         * @brief Check if the key is up
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyReleased() const;
        /**
         * @brief Check if the key is up
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyUp() const;

      private:
        int _key;
    };
} // namespace Otter::Graphic::Raylib

#endif /* !RAYLIBKEYBOARD_HPP_ */