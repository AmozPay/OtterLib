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
        _keyTypeKeyCodeMap = {{LEFT, raylib::KEY_LEFT},   {RIGHT, raylib::KEY_RIGHT},   {UP, raylib::KEY_UP},           {DOWN, raylib::KEY_DOWN},
                              {SPACE, raylib::KEY_SPACE}, {ESCAPE, raylib::KEY_ESCAPE}, {SHIFT, raylib::KEY_LEFT_SHIFT}};
    };

    RaylibKeyboard::~RaylibKeyboard() = default;

    void RaylibKeyboard::setExitKey(KeyType keyType) const { raylib::SetExitKey(getKeyCode(keyType)); }

    bool RaylibKeyboard::isKeyPressed(KeyType keyType) const { return raylib::IsKeyPressed(getKeyCode(keyType)); }

    bool RaylibKeyboard::isKeyDown(KeyType keyType) const { return raylib::IsKeyDown(getKeyCode(keyType)); }

    bool RaylibKeyboard::isKeyReleased(KeyType keyType) const { return raylib::IsKeyReleased(getKeyCode(keyType)); }

    bool RaylibKeyboard::isKeyUp(KeyType keyType) const { return raylib::IsKeyUp(getKeyCode(keyType)); }

    int RaylibKeyboard::getKeyPressed() { return raylib::GetKeyPressed(); }

    int RaylibKeyboard::getKeyCode(const KeyType& keyType) const
    {
        KeyTypeKeyCodeMap::const_iterator it = _keyTypeKeyCodeMap.find(keyType);

        if (it == _keyTypeKeyCodeMap.end())
            return -1;
        return it->second;
    }

} // namespace Otter::Graphic::Raylib