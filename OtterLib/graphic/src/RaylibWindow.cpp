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
        raylib::InitWindow(width, height, title.c_str());
    }

    RaylibWindow::~RaylibWindow() = default;

    //    RaylibWindow::~RaylibWindow() { CloseWindow(); }

    void RaylibWindow::setFramerateLimit(const int& framerate) { raylib::SetTargetFPS(framerate); }

    void RaylibWindow::setScreenHeight(const int& height) { raylib::SetWindowSize(raylib::GetScreenWidth(), height); }

    void RaylibWindow::setScreenWidth(const int& width) { raylib::SetWindowSize(width, raylib::GetScreenHeight()); }

    void RaylibWindow::setScreenSize(const int& width, const int& height) { raylib::SetWindowSize(width, height); }

    int RaylibWindow::getScreenWidth() { return raylib::GetScreenWidth(); }

    int RaylibWindow::getScreenHeight() { return raylib::GetScreenHeight(); }

    bool RaylibWindow::isOpen() { return !raylib::WindowShouldClose(); }

    void RaylibWindow::startDrawing() { raylib::BeginDrawing(); }

    void RaylibWindow::endDrawing() { raylib::EndDrawing(); }

    void RaylibWindow::clearBackground() { raylib::ClearBackground(raylib::BLACK); }

    void RaylibWindow::closeWindow()
    {
        std::cout << "close" << std::endl;
        raylib::CloseWindow();
    }
} // namespace Otter::Graphic::Raylib