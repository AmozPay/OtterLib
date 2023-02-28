/*
** EPITECH PROJECT, 2023
** RType
** File description:
** ParallaxSystem.cpp
*/

#include "baseComponents.hpp"
#include "ParallaxSystem.hpp"

namespace Otter::Games::RType::System::Parallax {

    void ParallaxHandler(Otter::Core::Orchestrator& ref)
    {
        auto const& parallaxes = ref.get_components<Otter::Core::BaseComponents::Parallax>();
        auto& transforms = ref.get_components<Otter::Core::BaseComponents::Transform>();
        auto const& textures = ref.get_components<Otter::Core::BaseComponents::Texture>();
        for (size_t i = 0; i < parallaxes.size() && i < transforms.size() && i < textures.size(); i++) {
            auto const& parallax = parallaxes[i];
            auto& transform = transforms[i];
            auto const& texture = textures[i];
            if (parallax && transform && texture) {
                if (transform->_position.x < -static_cast<float>(texture->_texture.getWidth()))
                    transform->_position.x = static_cast<float>(texture->_texture.getWidth());
            }
        }
    }

} // namespace Otter::Games::RType::System::Parallax