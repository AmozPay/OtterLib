/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibKeyboard.cpp
*/
#include "RaylibKeyboard.hpp"

namespace Otter::Graphic::Raylib {
    RaylibKeyboard::RaylibKeyboard() = default;

    RaylibKeyboard::~RaylibKeyboard() = default;

    void RaylibKeyboard::setKey(RaylibKey raylibKey, const int& state) { _keyMap[raylibKey] = state; }

    void RaylibKeyboard::removeKey(RaylibKey raylibKey) { _keyMap.erase(raylibKey); }

    void RaylibKeyboard::setExitKey(RaylibKey raylibKey) const { SetExitKey(raylibKey); }

    bool RaylibKeyboard::isKeyPressed(RaylibKey key) const { return IsKeyPressed(key); }

    bool RaylibKeyboard::isKeyDown(RaylibKey key) const { return IsKeyDown(key); }

    bool RaylibKeyboard::isKeyReleased(RaylibKey key) const { return IsKeyReleased(key); }

    bool RaylibKeyboard::isKeyUp(RaylibKey key) const { return IsKeyUp(key); }

    int RaylibKeyboard::getKeyPressed() { return GetKeyPressed(); }

    std::map<RaylibKeyboard::RaylibKey, int>::iterator RaylibKeyboard::begin() { return _keyMap.begin(); }

    std::map<RaylibKeyboard::RaylibKey, int>::iterator RaylibKeyboard::end() { return _keyMap.end(); }

} // namespace Otter::Graphic::Raylib