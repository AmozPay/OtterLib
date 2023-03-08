/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibMouse.cpp
*/
#include "RaylibMouse.hpp"

namespace Otter::Graphic::Raylib {

    Raylib::RaylibMouse::RaylibMouse(const int& button) : _button(button) {}

    RaylibMouse::~RaylibMouse() = default;

    void RaylibMouse::setButton(const int& button) { _button = button; }

    float RaylibMouse::getMouseWheelMove() { return raylib::GetMouseWheelMove(); }

    int RaylibMouse::getMouseX() { return raylib::GetMouseX(); }

    int RaylibMouse::getMouseY() { return raylib::GetMouseY(); }

    raylib::Vector2 RaylibMouse::getMousePosition() { return raylib::GetMousePosition(); }

    raylib::Vector2 RaylibMouse::getMouseDelta() { return raylib::GetMouseDelta(); }

    bool RaylibMouse::isMouseButtonPressed() const { return raylib::IsMouseButtonPressed(_button); }

    bool RaylibMouse::isMouseButtonDown() const { return raylib::IsMouseButtonDown(_button); }

    bool RaylibMouse::isMouseButtonReleased() const { return raylib::IsMouseButtonReleased(_button); }

    bool RaylibMouse::isMouseButtonUp() const { return raylib::IsMouseButtonUp(_button); }
} // namespace Otter::Graphic::Raylib