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
         */
        RaylibKeyboard();
        /**
         * @brief Destroy the Keyboard object
         */
        ~RaylibKeyboard();

        /**
         * @brief The Raylib key enum
         * @details The Raylib key enum
         * @enum RaylibKey::LEFT: The left key
         * @enum RaylibKey::RIGHT: The right key
         * @enum RaylibKey::UP: The up key
         * @enum RaylibKey::DOWN: The down key
         * @enum RaylibKey::SPACE: The space key
         * @enum RaylibKey::ESCAPE: The escape key
         */
        enum RaylibKey {
            LEFT = KEY_LEFT,
            RIGHT = KEY_RIGHT,
            UP = KEY_UP,
            DOWN = KEY_DOWN,
            SPACE = KEY_SPACE,
            ESCAPE = KEY_ESCAPE,
            SHIFT = KEY_RIGHT_SHIFT,
        };

        /**
         * @brief Add a key to the map
         * @param raylibKey: The Raylib key associated, the one
         * @param state: The state of the key (no sense in this lib, but used by the game)
         * @return Nothing
         */
        void setKey(RaylibKey raylibKey, const int& state);

        /**
         * @brief Remove a key from the map
         * @param raylibKey: The Raylib key associated
         * @return Nothing
         */
        void removeKey(RaylibKey raylibKey);

        /**
         * @brief Set the exit key
         * @param raylibKey: The Raylib key associated
         * @return Nothing
         */
        void setExitKey(RaylibKey raylibKey) const;

        /**
         * @brief Check if a key has been pressed once
         * @param key: The Raylib key to check
         * @return True if the key is pressed, false otherwise
         */
        [[nodiscard]] bool isKeyPressed(RaylibKey key) const;
        /**
         * @brief Check if a key is being pressed
         * @param key: The Raylib key to check
         * @return True if the key is down, false otherwise
         */
        [[nodiscard]] bool isKeyDown(RaylibKey key) const;
        /**
         * @brief Check if a key has been released once
         * @param key: The Raylib key to check
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyReleased(RaylibKey key) const;
        /**
         * @brief Check if a key is NOT being pressed
         * @param key: The Raylib key to check
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyUp(RaylibKey key) const;
        /**
         * @brief Get key pressed (keycode)
         * @details Call it multiple times for keys queued
         * @return The keycode of the key pressed, 0 if the queue is empty
         */
        static int getKeyPressed();

        /**
         * @brief Get the begin iterator of the key map
         * @return The begin iterator of the key map
         */
        std::map<RaylibKey, int>::iterator begin();

        /**
         * @brief Get the end iterator of the key map
         * @return The end iterator of the key map
         */
        std::map<RaylibKey, int>::iterator end();

      private:
        std::map<RaylibKey, int> _keyMap;
    };
} // namespace Otter::Graphic::Raylib

#endif /* !RAYLIBKEYBOARD_HPP_ */