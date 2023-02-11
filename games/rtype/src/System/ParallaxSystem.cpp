/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ParallaxSystem.cpp
*/
#include "ParallaxSystem.hpp"

namespace Otter::Games::RType::System::Parallax {

    void ParallaxMovement(Otter::Core::Orchestrator& ref)
    {
        auto const& parallaxes = ref.get_components<Otter::Games::RType::Components::Parallax>();
        auto& transforms = ref.get_components<Otter::Games::RType::Components::Transform>();
        auto const& textures = ref.get_components<Otter::Games::RType::Components::Texture>();
        for (size_t i = 0; i < parallaxes.size() && i < transforms.size() && i < textures.size(); i++) {
            auto const& parallax = parallaxes[i];
            auto& transform = transforms[i];
            auto const& texture = textures[i];
            if (parallax && transform && texture) {
                if (transform->_position.x < -(float)texture->_texture.getWidth())
                    transform->_position.x = (float)texture->_texture.getWidth();
            }
        }
    }

} // namespace Otter::Games::RType::System::Parallax