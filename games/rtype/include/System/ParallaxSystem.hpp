/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ParallaxSystem.hpp
*/

#ifndef RTYPE_PARALLAXSYSTEM_HPP
#define RTYPE_PARALLAXSYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Parallax {

    /**
     * @brief System for the handling of the parallax
     * @details The parallax system is used to move the entities based on their speed, acceleration and direction. When
     * the entity is out of the screen, it is moved to the other side
     * @param ref: The orchestrator
     * @return void
     */
    void ParallaxHandler(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::Parallax

#endif // RTYPE_PARALLAXSYSTEM_HPP