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
#include "Components.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::Animation {

    using Animation = Otter::Games::RType::Utils::Animation;
    using AnimationComponent = Otter::Games::RType::Components::AnimationComponent;
    using Texture = Otter::Core::BaseComponents::Texture;
    using TextureStorage = Otter::Core::BaseComponents::TextureStorage;
    using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
    using ComponentIdVector = Otter::Games::RType::Components::ComponentIdVector;
    using IdAnimMap = Otter::Games::RType::Components::IdAnimMap;

    bool checkOneShotEnd(
        const bool &isOneShot,
        const std::size_t &maxSize,
        const std::size_t &currentPos
    ) {
        return isOneShot && (currentPos >= maxSize - 1);
    }

    void changeTexture(Otter::Core::Orchestrator& ref, Animation& animation, Texture &texture) 
    {
        auto& textureStorages = ref.get_components<TextureStorage>();

        for (size_t x = 0; x < textureStorages.size(); x++) {
            auto& textureStorage = textureStorages[x];

            if (!textureStorage) {
                continue;
            }
            texture._texture = textureStorage->findTextureByPath(animation.texturePath);
        }        
    }

    void computeAnimation(Otter::Core::Orchestrator& ref, Animation& animation, Texture &texture)
    {
        TimePoint newTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> duration = (newTime - animation.lastTime) * 1000;
        bool oneShotEnd = checkOneShotEnd(
            animation.isOneShot,
            animation.animVect.size(),
            animation.currentPos
        );

        if (duration.count() >= animation.delay && !oneShotEnd) {
            animation.currentPos = animation.currentPos + 1;
            animation.lastTime = newTime;
            if (animation.currentPos >= animation.animVect.size()) {
                animation.currentPos = 0;
            }
            texture._rectangle = animation.animVect[animation.currentPos];
            if (animation.texturePath.compare(texture._texture.getFilePath()) != 0) {
                changeTexture(ref, animation, texture);
            }
        }
    }

    void animate(Otter::Core::Orchestrator& ref)
    {
        auto& animationsComponents = ref.get_components<AnimationComponent>();
        auto& textures = ref.get_components<Texture>();

        for (size_t x = 0; x < animationsComponents.size(); x++) {
            auto& animationComponent = animationsComponents[x];
            auto& texture = textures[x];

            if (!animationComponent || !texture) {
                continue;
            }
            
            if (animationComponent->idAnimMap.contains(animationComponent->currentAnim)) {
                computeAnimation(
                    ref,
                    animationComponent->idAnimMap
                    .find(animationComponent->currentAnim)->second,
                    *texture
                );
            }
        }
    }

    void handleAnim(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId)
    {
        
    }
} // namespace Otter::Games::RType::System::Animation
