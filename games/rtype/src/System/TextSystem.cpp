/*
** EPITECH PROJECT, 2023
** RType
** File description:
** TextSystem.cpp
*/

#include "baseComponents.hpp"
#include "TextSystem.hpp"

#include "Components.hpp"
#include "OtterGraphic.hpp"

namespace Otter::Games::RType::System::Text {

    namespace core = Otter::Core;

    void HealthTextChecker(core::Orchestrator& ref, auto& text, int textId)
    {
        const auto& healths = ref.get_components<core::BaseComponents::Health>();
        auto& transforms = ref.get_components<core::BaseComponents::Transform>();

        const int& entityId = text->_linkedEntityId;

        if (entityId != -1 && entityId < healths.size() && healths[entityId] && entityId < transforms.size() && transforms[entityId]) {
            const auto& health = healths[entityId];
            auto& entityTransform = transforms[entityId];
            auto& textTransform = transforms[textId];
            text->_text = std::to_string(health->_hp) + " HP";
            textTransform->_position = {entityTransform->_position.x, entityTransform->_position.y - 25};
        }
    }

    void UpdateHealthText(core::Orchestrator& ref)
    {
        auto& texts = ref.get_components<core::BaseComponents::Text>();

        for (size_t i = 0; i < texts.size(); i++) {
            auto& text = texts[i];

            if (text && text->_tag == ("health"))
                HealthTextChecker(ref, text, i);
        }
    }

    void DrawText(core::Orchestrator& ref)
    {
        auto& texts = ref.get_components<core::BaseComponents::Text>();
        auto const& transforms = ref.get_components<core::BaseComponents::Transform>();

        for (size_t i = 0; i < texts.size() && i < transforms.size(); i++) {
            auto& text = texts[i];
            auto const& transform = transforms[i];

            if (text && transform)
                text->_textInstance.draw(text->_text, {transform->_position.x, transform->_position.y}, text->_fontSize);
        }
    }

} // namespace Otter::Games::RType::System::Text