/*
** EPITECH PROJECT, 2023
** RType
** File description:
** TextSystem.hpp
*/

#ifndef RTYPE_TEXTSYSTEM_HPP
#define RTYPE_TEXTSYSTEM_HPP

#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Text {

    /**
     * @brief Update the text system for the health
     * @details Update the text for each entity with the text & health component
     * @param ref: The orchestrator
     * @return void
     */
    void UpdateHealthText(Otter::Core::Orchestrator& ref);

    /**
     * @brief Draw the text system
     * @details Draw the text for each entity with the text component
     * @param ref: The orchestrator
     * @return void
     */
    void DrawText(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::Text

#endif // RTYPE_TEXTSYSTEM_HPP