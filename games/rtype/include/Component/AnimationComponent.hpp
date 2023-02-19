/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** AnimationComponent
*/

#ifndef ANIMATIONCOMPONENT_HPP_
#define ANIMATIONCOMPONENT_HPP_

#include "Animation.hpp"
#include <string>

namespace Otter::Games::RType::Components {

    using Animation = Otter::Games::RType::Utils::Animation;
    using IdAnimMap = std::unordered_map<std::size_t, Animation>;

    struct AnimationComponent {
        AnimationComponent(const IdAnimMap &idAnimMap, const std::size_t &currentAnim)
        {
            this->idAnimMap = idAnimMap;
            this->currentAnim = currentAnim;
        };

        ~AnimationComponent() = default;

        IdAnimMap idAnimMap;
        std::size_t currentAnim;
    };
    
};

#endif /* !ANIMATIONCOMPONENT_HPP_ */
