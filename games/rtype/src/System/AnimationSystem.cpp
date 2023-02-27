/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** AnimationSystem
*/

#include "AnimationSystem.hpp"

#include "Animation.hpp"
#include "AnimationComponent.hpp"
#include "EventComponent.hpp"

namespace Otter::Games::RType::System::Animation {

    using Animation = Otter::Games::RType::Utils::Animation;
    using AnimationComponent = Otter::Games::RType::Components::AnimationComponent;
    using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
    using ComponentIdVector = Otter::Games::RType::Components::ComponentIdVector;
    using IdAnimMap = Otter::Games::RType::Components::IdAnimMap;

    void computeAnimation(Animation& animation)
    {
        TimePoint newTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> duration = (newTime - animation.lastTime) * 1000;

        if (duration.count() >= animation.delay) {
            animation.currentPos += 1;
            animation.lastTime = newTime;
            if (animation.currentPos == animation.animVect.end()) {
                animation.currentPos = animation.animVect.begin();
            }
        }
    }

    void animate(Otter::Core::Orchestrator& ref)
    {
        auto& animationsComponents = ref.get_components<AnimationComponent>();

        for (size_t x = 0; x < animationsComponents.size(); x++) {
            auto& animationComponent = animationsComponents[x];

            if (!animationComponent) {
                continue;
            }

            IdAnimMap::iterator anim = animationComponent->idAnimMap.find(animationComponent->currentAnim);

            if (anim == animationComponent->idAnimMap.end()) {
                computeAnimation(anim->second);
            }
        }
    }
} // namespace Otter::Games::RType::System::Animation
