/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include "Utils.hpp"
#include <chrono>
#include <vector>

namespace Otter::Games::RType::Utils {
    using Rectangle = Otter::Games::RType::Utils::Rectangle;
    using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
    using AnimRectVect = std::vector<Rectangle>;

    struct Animation {
        Animation(const AnimRectVect &animVect, const float &delay)
        {
            this->animVect = animVect;
            this->currentPos = this->animVect.begin();
            this->delay = delay;
            this->lastTime = std::chrono::steady_clock::now();
        };

        ~Animation() = default;

        AnimRectVect animVect;
        AnimRectVect::iterator currentPos;
        TimePoint lastTime;
        float delay;
    };

} // namespace Otter::Games::RType::Utils

#endif /* !ANIMATION_HPP_ */
