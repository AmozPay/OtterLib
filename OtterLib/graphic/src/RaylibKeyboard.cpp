/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibKeyboard.cpp
*/
#include "RaylibKeyboard.hpp"

namespace Otter::Graphic::Raylib {
    RaylibKeyboard::RaylibKeyboard(const int& key) : _key(key) {}

    RaylibKeyboard::~RaylibKeyboard() = default;

    void RaylibKeyboard::setKey(const int& key) { _key = key; }

    void RaylibKeyboard::setExitKey() const { SetExitKey(_key); }

    bool RaylibKeyboard::isKeyPressed() const { return IsKeyPressed(_key); }

    bool RaylibKeyboard::isKeyDown() const { return IsKeyDown(_key); }

    bool RaylibKeyboard::isKeyReleased() const { return IsKeyReleased(_key); }

    bool RaylibKeyboard::isKeyUp() const { return IsKeyUp(_key); }
} // namespace Otter::Graphic::Raylib