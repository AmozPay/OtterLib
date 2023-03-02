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

    void HealthTextChecker(core::Orchestrator& ref, auto& text)
    {
        const auto& healths = ref.get_components<core::BaseComponents::Health>();

        const int& entityId = text->_linkedEntityId;

        if (entityId != -1 && entityId < healths.size() && healths[entityId]) {
            const auto& health = healths[entityId];
            text->_text = std::to_string(health->_hp);
        }
    }

    void UpdateHealthText(core::Orchestrator& ref)
    {
        auto& texts = ref.get_components<core::BaseComponents::Text>();

        for (size_t i = 0; i < texts.size(); i++) {
            auto& text = texts[i];

            if (text && text->_tag == ("health"))
                HealthTextChecker(ref, text);
        }
    }

    void DrawText(core::Orchestrator& ref)
    {
        auto& texts = ref.register_component<core::BaseComponents::Text>();
        const auto& transforms = ref.register_component<core::BaseComponents::Transform>();

        for (size_t i = 0; i < texts.size() && i < transforms.size(); i++) {
            auto& text = texts[i];
            const auto& transform = transforms[i];

            if (text)
                text->_textInstance.draw(text->_text, {transform->_position.x, transform->_position.y}, text->_fontSize);
        }
    }

} // namespace Otter::Games::RType::System::Text