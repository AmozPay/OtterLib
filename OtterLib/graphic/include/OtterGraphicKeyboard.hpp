/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** OtterGraphicKeyboard
*/

#ifndef OTTERGRAPHICKEYBOARD_HPP_
#define OTTERGRAPHICKEYBOARD_HPP_

#include "Raylib.hpp"

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic {
    /**
     * @brief The Keyboard interface for keyboard management
     */
    class IKeyboard {
      public:
        /**
         * @brief Destroy the Keyboard object
         */
        virtual ~IKeyboard() = default;

        /**
         * @brief The key enum
         * @details The key enum
         * @enum Key::LEFT: The left key
         * @enum Key::RIGHT: The right key
         * @enum Key::UP: The up key
         * @enum Key::DOWN: The down key
         * @enum Key::SPACE: The space key
         * @enum Key::ESCAPE: The escape key
         */
        enum KeyType {
            LEFT,
            RIGHT,
            UP,
            DOWN,
            SPACE,
            ESCAPE,
            SHIFT,
        };

        /**
         * @brief Add a key to the map
         * @param y: The Raylib key associated, the one
         * @param state: The state of the key (no sense in this lib, but used by the game)
         * @return Nothing
         */
        void setKey(KeyType y, const int& state);

        /**
         * @brief Remove a key from the map
         * @param y: The Raylib key associated
         * @return Nothing
         */
        void removeKey(KeyType y);

        /**
         * @brief Set the exit key
         * @param y: The Raylib key associated
         * @return Nothing
         */
        void setExitKey(KeyType y) const;

        /**
         * @brief Check if a key has been pressed once
         * @param key: The Raylib key to check
         * @return True if the key is pressed, false otherwise
         */
        [[nodiscard]] bool isKeyPressed(KeyType key) const;
        /**
         * @brief Check if a key is being pressed
         * @param key: The Raylib key to check
         * @return True if the key is down, false otherwise
         */
        [[nodiscard]] bool isKeyDown(KeyType key) const;
        /**
         * @brief Check if a key has been released once
         * @param key: The Raylib key to check
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyReleased(KeyType key) const;
        /**
         * @brief Check if a key is NOT being pressed
         * @param key: The Raylib key to check
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyUp(KeyType key) const;
        /**
         * @brief Get key pressed (keycode)
         * @details Call it multiple times for keys queued
         * @return The keycode of the key pressed, 0 if the queue is empty
         */
        static int getKeyPressed();
    };
} // namespace Otter::Graphic

#endif /* !OTTERGRAPHICKEYBOARD_HPP_ */