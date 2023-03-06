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
#include <string>
#include <vector>

namespace Otter::Games::RType::Utils {
    using Rectangle = Otter::Games::RType::Utils::Rectangle;
    using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
    using AnimRectVect = std::vector<Rectangle>;

    struct Animation {
        Animation(const std::string& texturePath, const AnimRectVect& animVect, const float& delay,
                  const bool& isOneShot = false)
        {
            this->texturePath = texturePath;
            this->animVect = animVect;
            this->currentPos = 0;
            this->delay = delay;
            this->lastTime = std::chrono::steady_clock::now();
            this->isOneShot = isOneShot;
        };

        ~Animation() = default;

        std::string texturePath;
        AnimRectVect animVect;
        std::size_t currentPos;
        TimePoint lastTime;
        float delay;
        bool isOneShot;
    };

} // namespace Otter::Games::RType::Utils

#endif /* !ANIMATION_HPP_ */
