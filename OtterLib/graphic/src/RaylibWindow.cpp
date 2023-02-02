/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibWindow.cpp
*/

#include "RaylibWindow.hpp"

namespace Otter::Graphic::Raylib {
    RaylibWindow::RaylibWindow(const int& height, const int& width, const std::string& title)
    {
        InitWindow(width, height, title.c_str());
    }

    RaylibWindow::~RaylibWindow() = default;
//    RaylibWindow::~RaylibWindow() { CloseWindow(); }

    void RaylibWindow::setFramerateLimit(const int& framerate) { SetTargetFPS(framerate); }

    void RaylibWindow::setScreenHeight(const int& height) { SetWindowSize(GetScreenWidth(), height); }

    void RaylibWindow::setScreenWidth(const int& width) { SetWindowSize(width, GetScreenHeight()); }

    void RaylibWindow::setScreenSize(const int& width, const int& height) { SetWindowSize(width, height); }

    int RaylibWindow::getScreenWidth() { return GetScreenWidth(); }

    int RaylibWindow::getScreenHeight() { return GetScreenHeight(); }

    bool RaylibWindow::isOpen() { return !WindowShouldClose(); }

    void RaylibWindow::startDrawing() { BeginDrawing(); }

    void RaylibWindow::endDrawing() { EndDrawing(); }

    void RaylibWindow::clearBackground() { ClearBackground(RAYWHITE); }
} // namespace Otter::Graphic::Raylib