/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** AnimationSystem
*/

#ifndef ANIMATIONSYSTEM_HPP_
#define ANIMATIONSYSTEM_HPP_

#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Animation {

    /**
     * @brief System for sprites animation
     * @details Move sprite rect for 2d animation
     * @param ref: The orchestrator
     * @return void
     */
    void animate(Otter::Core::Orchestrator& ref);
}

#endif /* !ANIMATIONSYSTEM_HPP_ */
