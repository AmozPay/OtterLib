/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibKeyboard.hpp
*/

#ifndef RAYLIBKEYBOARD_HPP_
#define RAYLIBKEYBOARD_HPP_

#include "OtterGraphicKeyboard.hpp"
#include "Raylib.hpp"

#include <unordered_map>

using KeyType = Otter::Graphic::IKeyboard::KeyType;
using KeyTypeKeyCodeMap = std::unordered_map<KeyType, int>;

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {
    /**
     * @brief The RaylibKeyboard class for Raylib keyboard management
     */
    class RaylibKeyboard : public Otter::Graphic::IKeyboard {
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
         * @brief Add a key to the map
         * @param raylibKey: The Raylib key associated, the one
         * @param state: The state of the key (no sense in this lib, but used by the game)
         * @return Nothing
         */
        void setKey(KeyType raylibKey, const int& state);

        /**
         * @brief Remove a key from the map
         * @param raylibKey: The Raylib key associated
         * @return Nothing
         */
        void removeKey(KeyType raylibKey);

        /**
         * @brief Set the exit key
         * @param raylibKey: The Raylib key associated
         * @return Nothing
         */
        void setExitKey(KeyType raylibKey) const;

        /**
         * @brief Check if a key has been pressed once
         * @param key: The Raylib key to check
         * @return True if the key is pressed, false otherwise
         */
        [[nodiscard]] bool isKeyPressed(KeyType keyType) const;
        /**
         * @brief Check if a key is being pressed
         * @param key: The Raylib key to check
         * @return True if the key is down, false otherwise
         */
        [[nodiscard]] bool isKeyDown(KeyType keyType) const;
        /**
         * @brief Check if a key has been released once
         * @param key: The Raylib key to check
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyReleased(KeyType keyType) const;
        /**
         * @brief Check if a key is NOT being pressed
         * @param key: The Raylib key to check
         * @return True if the key is up, false otherwise
         */
        [[nodiscard]] bool isKeyUp(KeyType keyType) const;
        /**
         * @brief Get key pressed (keycode)
         * @details Call it multiple times for keys queued
         * @return The keycode of the key pressed, 0 if the queue is empty
         */
        static int getKeyPressed();

      private:
        int getKeyCode(const KeyType& keyType) const;
        KeyTypeKeyCodeMap _keyTypeKeyCodeMap;
    };
} // namespace Otter::Graphic::Raylib

#endif /* !RAYLIBKEYBOARD_HPP_ */