/*
** EPITECH PROJECT, 2023
** RType
** File description:
** DispawnableSystem.cpp
*/

#include "baseComponents.hpp"
#include "DispawnableSystem.hpp"

namespace Otter::Games::RType::System::Dispawnable {

    void EntityDispawn(Otter::Core::Orchestrator& ref)
    {
        auto& transforms = ref.get_components<Otter::Core::BaseComponents::Transform>();
        auto& textures = ref.get_components<Otter::Core::BaseComponents::Texture>();
        auto& dispawnables = ref.get_components<Otter::Core::BaseComponents::Dispawnable>();
        for (size_t i = 0; i < transforms.size() && i < dispawnables.size(); i++) {
            auto& transform = transforms[i];
            auto& texture = textures[i];
            auto& dispawnable = dispawnables[i];
            if (transform && dispawnable && texture) {
                // TODO: need to check if the entity is out of the screen (up, down, right)
                if (transform->_position.x < -(static_cast<float>(texture->_texture.getWidth()) * transform->_scale))
                    ref.remove_entity(i);
            }
        }
    }

} // namespace Otter::Games::RType::System::Dispawnable