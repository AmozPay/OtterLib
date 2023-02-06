/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventSystem.cpp
*/

#include "EventSystem.hpp"

#include "Components.hpp"
#include "OtterGraphic.hpp"

namespace Otter::Games::RType::System::Event {

    void PollEvent(Otter::Core::Orchestrator& ref)
    {
        auto const& players = ref.get_components<Otter::Games::RType::Components::Player>();
        auto& velocities = ref.get_components<Otter::Games::RType::Components::Velocity>();
        auto& keyboards = ref.get_components<Otter::Games::RType::Components::Keyboard>();
        auto& eventNetworks = ref.get_components<Otter::Games::RType::Components::EventNetwork>();
        for (size_t i = 0; i < players.size() && i < velocities.size() && i < keyboards.size(); i++) {
            auto const& player = players[i];
            auto& velocity = velocities[i];
            auto& keyboard = keyboards[i];
            auto& eventNetwork = eventNetworks[i];
            if (velocity && keyboard) {
                for (auto it = keyboard->_keyboard.begin(); it != keyboard->_keyboard.end(); it++) {
                    if (keyboard->_keyboard.isKeyDown(it->first)) {
                        eventNetwork->_data = it->second;
                        //                        EventHandler(ref, i, velocity, player,
                        //                        (Otter::Games::RType::Utils::EventState)it->second);
                        // TODO: add keyboard management for other entities
                    }
                }
            }
        }
    }

} // namespace Otter::Games::RType::System::Event