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
#include <unordered_map>

namespace Otter::Games::RType::Components {

    enum AnimType {
        STANDUP_ANIM,
        RUNNING_ANIM,
        DEATH_ANIM
    };

    using Animation = Otter::Games::RType::Utils::Animation;
    using IdAnimMap = std::unordered_map<AnimType, Animation>;

    /**
     * @brief Component for handling animations
     * @details The goal of this component is to register
     * animations with their ids.
     * @struct AnimationComponent
     */
    struct AnimationComponent {
        AnimationComponent(const IdAnimMap& idAnimMap, const AnimType& currentAnim)
        {
            this->idAnimMap = idAnimMap;
            this->currentAnim = currentAnim;
        };

        ~AnimationComponent() = default;

        IdAnimMap idAnimMap;
        AnimType currentAnim;
    };

}; // namespace Otter::Games::RType::Components

#endif /* !ANIMATIONCOMPONENT_HPP_ */
