/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** AnimationComponent
*/

#ifndef ANIMATIONCOMPONENT_HPP_
#define ANIMATIONCOMPONENT_HPP_

#include "Utils.hpp"
#include <chrono>

namespace Otter::Games::RType::Components {
    using Rect = Otter::Games::RType::Utils::Rect;
    using Clock = std::chrono::time_point<std::chrono::steady_clock>;

    struct AnimationComponent {
        AnimationComponent(Rect animRect, Rect moveRect, float delay) {
            this->animRect = animRect;
            this->moveRect = moveRect;
            this->delay = delay;
            this->lastTime = std::chrono::steady_clock::now();
        };

        ~AnimationComponent() = default;

        Rect animRect;
        Rect moveRect;
        Clock lastTime;
        float delay;
    };
};

#endif /* !ANIMATIONCOMPONENT_HPP_ */
