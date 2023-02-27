/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibKeyboard.cpp
*/
#include "RaylibKeyboard.hpp"

namespace Otter::Graphic::Raylib {
    RaylibKeyboard::RaylibKeyboard()
    {
        _keyTypeKeyCodeMap = {{LEFT, KEY_LEFT},   {RIGHT, KEY_RIGHT},   {UP, KEY_UP},           {DOWN, KEY_DOWN},
                              {SPACE, KEY_SPACE}, {ESCAPE, KEY_ESCAPE}, {SHIFT, KEY_LEFT_SHIFT}};
    };

    RaylibKeyboard::~RaylibKeyboard() = default;

    void RaylibKeyboard::setExitKey(KeyType keyType) const { SetExitKey(getKeyCode(keyType)); }

    bool RaylibKeyboard::isKeyPressed(KeyType keyType) const { return IsKeyPressed(getKeyCode(keyType)); }

    bool RaylibKeyboard::isKeyDown(KeyType keyType) const { return IsKeyDown(getKeyCode(keyType)); }

    bool RaylibKeyboard::isKeyReleased(KeyType keyType) const { return IsKeyReleased(getKeyCode(keyType)); }

    bool RaylibKeyboard::isKeyUp(KeyType keyType) const { return IsKeyUp(getKeyCode(keyType)); }

    int RaylibKeyboard::getKeyPressed() { return GetKeyPressed(); }

    int RaylibKeyboard::getKeyCode(const KeyType& keyType) const
    {
        KeyTypeKeyCodeMap::const_iterator it = _keyTypeKeyCodeMap.find(keyType);

        if (it == _keyTypeKeyCodeMap.end())
            return -1;
        return it->second;
    }

} // namespace Otter::Graphic::Raylib