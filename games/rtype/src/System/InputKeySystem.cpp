/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventSystem.cpp
*/

#include "InputKeySystem.hpp"
#include "baseComponents.hpp"
#include "Components.hpp"
#include "OtterGraphic.hpp"

namespace Otter::Games::RType::System::Event {

    void PollEvent(Otter::Core::Orchestrator& ref)
    {
        auto& keyboards = ref.get_components<Otter::Core::BaseComponents::Keyboard>();
        auto& eventNetworks = ref.get_components<Otter::Core::BaseComponents::EventNetwork>();
        for (size_t i = 0; i < keyboards.size() && i < eventNetworks.size(); i++) {
            auto& keyboard = keyboards[i];
            auto& eventNetwork = eventNetworks[i];
            if (keyboard && eventNetwork) {
                for (auto it = keyboard->begin(); it != keyboard->end(); it++) {
                    if (keyboard->_keyboard.isKeyDown(it->first)) {
                        eventNetwork->_data = it->second;
                    }
                }
            }
        }
    }

} // namespace Otter::Games::RType::System::Event