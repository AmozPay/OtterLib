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
                sprite->_texture.draw(Rectangle(sprite->_rectangle.x, sprite->_rectangle.y, sprite->_rectangle.width,
                                                sprite->_rectangle.height),
                                      {transform->_position.x, transform->_position.y}, transform->_rotation,
                                      transform->_scale);
            }
        }
    }

    void Draw(Otter::Core::Orchestrator& ref)
    {
        auto& sprites = ref.get_components<Otter::Games::RType::Components::Texture>();
        auto const& transforms = ref.get_components<Otter::Games::RType::Components::Transform>();
        auto const& renders = ref.get_components<Otter::Games::RType::Components::Render>();
        auto const& parallaxes = ref.get_components<Otter::Games::RType::Components::Parallax>();
        for (size_t i = 0; i < sprites.size() && i < transforms.size() && i < renders.size(); i++) {
            if (i < parallaxes.size() && parallaxes[i])
                continue;
            auto& sprite = sprites[i];
            auto const& transform = transforms[i];
            auto const& render = renders[i];
            if (sprite && transform && render) {
                sprite->_texture.draw(Rectangle(sprite->_rectangle.x, sprite->_rectangle.y, sprite->_rectangle.width,
                                                sprite->_rectangle.height),
                                      {transform->_position.x, transform->_position.y}, transform->_rotation,
                                      transform->_scale);
            }
        }
    }

} // namespace Otter::Games::RType::System::Sprite