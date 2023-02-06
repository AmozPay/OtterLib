/*
** EPITECH PROJECT, 2023
** RType
** File description:
** SpriteSystem.cpp
*/

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Sprite {

    void DrawParallax(Otter::Core::Orchestrator& ref)
    {
        auto& sprites = ref.get_components<Otter::Games::RType::Components::Texture>();
        auto const& transforms = ref.get_components<Otter::Games::RType::Components::Transform>();
        auto const& renders = ref.get_components<Otter::Games::RType::Components::Render>();
        auto const& parallaxes = ref.get_components<Otter::Games::RType::Components::Parallax>();
        for (size_t i = 0; i < sprites.size() && i < transforms.size() && i < renders.size() && i < parallaxes.size();
             i++) {
            if (!parallaxes[i])
                continue;
            auto& sprite = sprites[i];
            auto const& transform = transforms[i];
            auto const& render = renders[i];
            if (sprite && transform && render) {
                sprite->_texture.setScale(transform->_scale);
                sprite->_texture.setRotation(transform->_rotation);
                sprite->_texture.draw({transform->_position.x, transform->_position.y});
            }
        }
    }

    void Draw(Otter::Core::Orchestrator& ref)
    {
        auto& sprites = ref.get_components<Otter::Games::RType::Components::Texture>();
        auto& transforms = ref.get_components<Otter::Games::RType::Components::Transform>();
        auto const& renders = ref.get_components<Otter::Games::RType::Components::Render>();
        auto const& parallaxes = ref.get_components<Otter::Games::RType::Components::Parallax>();
        for (size_t i = 0; i < sprites.size() && i < transforms.size() && i < renders.size(); i++) {
            if (parallaxes[i])
                continue;
            auto& sprite = sprites[i];
            auto & transform = transforms[i];
            auto const& render = renders[i];
            if (sprite && transform && render) {
                sprite->_texture.setScale(transform->_scale);
                sprite->_texture.setRotation(transform->_rotation);
                sprite->_texture.draw({transform->_position->x, transform->_position->y});
            }
        }
    }

} // namespace Otter::Games::RType::System::Sprite