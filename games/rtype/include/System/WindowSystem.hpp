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
    /**
     * @brief Open a window
     * @details Open a window with the stored parameters
     * @param ref: The orchestrator
     * @return void
     */
    void OpenWindow(Otter::Core::Orchestrator& ref);

    /**
     * @brief Close the window
     * @details Close the window and remove the component
     * @param ref: The orchestrator
     * @return void
     */
    void CloseWindow(Otter::Core::Orchestrator& ref);

    /**
     * @brief Set the target framerate
     * @details Set the target framerate of the window with the stored parameters
     * @param ref: The orchestrator
     * @return void
     */
    void SetTargetFPS(Otter::Core::Orchestrator& ref);

    /**
     * @brief Start drawing
     * @param ref: The orchestrator
     * @return void
     */
    void BeginDraw(Otter::Core::Orchestrator& ref);
    /**
     * @brief End drawing
     * @param ref: The orchestrator
     * @return void
     */
    void EndDraw(Otter::Core::Orchestrator& ref);

    /**
     * @brief Clear the background
     * @details Clear the background, specialy used before drawing
     * @param ref
     */
    void ClearBackground(Otter::Core::Orchestrator& ref);
} // namespace Otter::Games::RType::System::Window

#endif // RTYPE_WINDOWSYSTEM_HPP