/*
** EPITECH PROJECT, 2023
** RType
** File description:
** WindowSystem.cpp
*/

#include "WindowSystem.hpp"

namespace Otter::Games::RType::System::Window {

    void OpenWindow(Otter::Core::Orchestrator& ref) {
        Otter::Graphic::Raylib::RaylibWindow window(800, 600, "RType");
        
    }

    void CloseWindow(Otter::Core::Orchestrator& ref) {
         
    }

} // namespace Otter::Games::RType::System::Window