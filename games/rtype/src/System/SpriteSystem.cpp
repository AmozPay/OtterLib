/*
** EPITECH PROJECT, 2023
** RType
** File description:
** SpriteSystem.cpp
*/

#include "Components.hpp"
#include "OtterCore.hpp"
#include "OtterGraphic.hpp"

namespace Otter::Games::RType::System::Sprite {

    void Load(Otter::Core::Orchestrator& ref)
    {
        auto const& sprites = ref.get_components<Otter::Games::RType::Components::Texture>();
        for (size_t i = 0; i < sprites.size(); i++) {
            auto const& sprite = sprites[i];
            if (sprite) {
                sprite->texture = Otter::Graphic::Raylib::RaylibTexture(sprite->path);
            }
        }
    }

    void Draw(Otter::Core::Orchestrator& ref)
    {
        auto const& sprites = ref.get_components<Otter::Games::RType::Components::Texture>();
        auto const& transforms = ref.get_components<Otter::Games::RType::Components::Transform>();
        for (size_t i = 0; i < sprites.size() && i < transforms.size(); i++) {
            auto const& sprite = sprites[i];
            auto const& transform = transforms[i];
            if (sprite && transform) {
                sprite->texture.setScale(transform->scale);
                sprite->texture.setRotation(transform->rotation);
                sprite->texture.draw({transform->position.x, transform->position.y});
            }
        }
    }

} // namespace Otter::Games::RType::System::Sprite