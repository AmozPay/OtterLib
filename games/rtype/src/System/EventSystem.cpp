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

    void PlayerMovementEvent(auto& velocity, Otter::Games::RType::Utils::EventState state)
    {
        // TODO: clean the state do not use RaylibKey::XX but a custom enum of the state of the player like FORWARD,
        // BACKWARD...
        if (state == Otter::Games::RType::Utils::EventState::BACKWARD) {
            velocity->_accelerationDirection.x += -1;
            std::cout << "LEFT Key" << std::endl;
        }
        if (state == Otter::Games::RType::Utils::EventState::FORWARD) {
            velocity->_accelerationDirection.x += 1;
            std::cout << "RIGHT Key" << std::endl;
        }
        if (state == Otter::Games::RType::Utils::EventState::UP) {
            velocity->_accelerationDirection.y += -1;
            std::cout << "UP Key" << std::endl;
        }
        if (state == Otter::Games::RType::Utils::EventState::DOWN) {
            velocity->_accelerationDirection.y += 1;
            std::cout << "DOWN Key" << std::endl;
        }
    }

    void EventHandler(auto& velocity, auto& player, Otter::Games::RType::Utils::EventState state)
    {
        if (player)
            PlayerMovementEvent(velocity, state);
        //        if (state == Otter::Games::RType::Utils::CLOSE)
        // TODO: close the window if this key is pressed
    }

    void PollEvent(Otter::Core::Orchestrator& ref)
    {
        auto const& players = ref.get_components<Otter::Games::RType::Components::Player>();
        auto& velocities = ref.get_components<Otter::Games::RType::Components::Velocity>();
        auto& keyboards = ref.get_components<Otter::Games::RType::Components::Keyboard>();
        for (size_t i = 0; i < players.size() && i < velocities.size() && i < keyboards.size(); i++) {
            auto const& player = players[i];
            auto& velocity = velocities[i];
            auto& keyboard = keyboards[i];
            if (velocity && keyboard) {
                for (auto it = keyboard->_keyboard.begin(); it != keyboard->_keyboard.end(); it++) {
                    if (keyboard->_keyboard.isKeyDown(it->first)) {
                        EventHandler(velocity, player, (Otter::Games::RType::Utils::EventState)it->second);
                        // TODO: add keyboard management for other entities
                    }
                }
            }
        }
    }

} // namespace Otter::Games::RType::System::Event