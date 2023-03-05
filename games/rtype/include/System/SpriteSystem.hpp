/*
** EPITECH PROJECT, 2023
** RType
** File description:
** SpriteSystem.hpp
*/

#ifndef RTYPE_SPRITESYSTEM_HPP
#define RTYPE_SPRITESYSTEM_HPP

#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Sprite {

    /**
     * @brief Draw the parallax system
     * @details Draw the texture for each entity with the texture and parallax component
     * @param ref: The orchestrator
     * @return void
     */
    void DrawParallax(Otter::Core::Orchestrator& ref);

    /**
     * @brief Draw the sprite system
     * @details Draw the texture for each entity with the texture component
     * @param ref: The orchestrator
     * @return void
     */
    void Draw(Otter::Core::Orchestrator& ref);
} // namespace Otter::Games::RType::System::Sprite

#endif // RTYPE_SPRITESYSTEM_HPP