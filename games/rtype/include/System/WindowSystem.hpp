/*
** EPITECH PROJECT, 2023
** RType
** File description:
** WindowSystem.hpp
*/

#ifndef RTYPE_WINDOWSYSTEM_HPP
#define RTYPE_WINDOWSYSTEM_HPP

#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Window {
    void OpenWindow(Otter::Core::Orchestrator& ref);

    void CloseWindow(Otter::Core::Orchestrator& ref);
} // namespace Otter::Games::RType::System::Window

#endif // RTYPE_WINDOWSYSTEM_HPP