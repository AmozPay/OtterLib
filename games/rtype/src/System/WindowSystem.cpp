/*
** EPITECH PROJECT, 2023
** RType
** File description:
** WindowSystem.cpp
*/

#include "WindowSystem.hpp"

#include "Components.hpp"
#include "OtterGraphic.hpp"
#include "baseComponents.hpp"

#include <cstdlib>

namespace Otter::Games::RType::System::Window {

    //    void OpenWindow(Otter::Core::Orchestrator& ref)
    //    {
    //        auto const& windows = ref.get_components<Otter::Games::RType::Components::Window>();
    //        for (size_t i = 0; i < windows.size(); i++) {
    //            auto const& window = windows[i];
    //            if (window) {
    //                window->window = Otter::Graphic::Raylib::RaylibWindow(window->height, window->width,
    //                window->title);
    //            }
    //        }
    //    }
    //
    //    void CloseWindow(Otter::Core::Orchestrator& ref)
    //    {
    //        auto const& windows = ref.get_components<Otter::Games::RType::Components::Window>();
    //        for (size_t i = 0; i < windows.size(); i++) {
    //            auto const& window = windows[i];
    //            if (window) {
    //                ref.remove_component<Otter::Games::RType::Components::Window>(i);
    //            }
    //        }
    //    }

    void SetTargetFPS(Otter::Core::Orchestrator& ref)
    {
        auto const& windows = ref.get_components<Otter::Core::BaseComponents::Window>();
        for (size_t i = 0; i < windows.size(); i++) {
            auto const& window = windows[i];
            if (window) {
                window->_window.setFramerateLimit(window->_fps);
            }
        }
    }

    void BeginDraw(Otter::Core::Orchestrator& ref)
    {
        auto const& windows = ref.get_components<Otter::Core::BaseComponents::Window>();
        for (size_t i = 0; i < windows.size(); i++) {
            auto const& window = windows[i];
            if (window) {
                window->_window.startDrawing();
            }
        }
    }

    void EndDraw(Otter::Core::Orchestrator& ref)
    {
        auto const& windows = ref.get_components<Otter::Core::BaseComponents::Window>();
        for (size_t i = 0; i < windows.size(); i++) {
            auto const& window = windows[i];

            if (!window)
                continue;
            if (window->_window.isOpen())
                window->_window.endDrawing();
        }
    }

    void ClearBackground(Otter::Core::Orchestrator& ref)
    {
        auto const& windows = ref.get_components<Otter::Core::BaseComponents::Window>();
        for (size_t i = 0; i < windows.size(); i++) {
            auto const& window = windows[i];

            if (!window)
                continue;

            if (window->_window.isOpen())
                window->_window.clearBackground();
        }
    }

    void WindowShouldClose(Otter::Core::Orchestrator& ref)
    {
        auto& windows = ref.get_components<Otter::Core::BaseComponents::Window>();
        for (size_t i = 0; i < windows.size(); i++) {
            auto& window = windows[i];
            if (window) {
                if (!window->_window.isOpen()) {
                    window->_window.closeWindow();
                    std::exit(0);
                }
            }
        }
    }

} // namespace Otter::Games::RType::System::Window