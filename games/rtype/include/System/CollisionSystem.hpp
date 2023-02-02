/*
** EPITECH PROJECT, 2023
** RType
** File description:
** SpriteSystem.hpp
*/

#ifndef RTYPE_SPRITESYSTEM_HPP
#define RTYPE_SPRITESYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"
#include "RaylibTexture.hpp"

namespace Otter::Games::RType::System::Collision {
    void EntityCollision(Otter::Core::Orchestrator& ref);

    enum CollisionDirection { TOP, BOTTOM, LEFT, RIGHT };
} // namespace Otter::Games::RType::System::Collision

#endif // RTYPE_SPRITESYSTEM_HPP