/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibMouse.cpp
*/
#include "RaylibMouse.hpp"

namespace Otter::Graphic::Raylib
{

    Raylib::RaylibMouse::RaylibMouse(const int &button) : _button(button)
    {}

    RaylibMouse::~RaylibMouse() = default;

    void RaylibMouse::setButton(const int &button) {
        _button = button;
    }

    float RaylibMouse::getMouseWheelMove() {
        return GetMouseWheelMove();
    }

    int RaylibMouse::getMouseX() {
        return GetMouseX();
    }

    int RaylibMouse::getMouseY() {
        return GetMouseY();
    }

    Vector2 RaylibMouse::getMousePosition() {
        return GetMousePosition();
    }

    Vector2 RaylibMouse::getMouseDelta() {
        return GetMouseDelta();
    }

    bool RaylibMouse::isMouseButtonPressed() const {
        return IsMouseButtonPressed(_button);
    }

    bool RaylibMouse::isMouseButtonDown() const {
        return IsMouseButtonDown(_button);
    }

    bool RaylibMouse::isMouseButtonReleased() const {
        return IsMouseButtonReleased(_button);
    }

    bool RaylibMouse::isMouseButtonUp() const {
        return IsMouseButtonUp(_button);
    }
}