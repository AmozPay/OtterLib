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

    void PlayerMovementEvent(auto& velocity, int keyPressed)
    {
        if (keyPressed == Otter::Graphic::Raylib::RaylibKeyboard::RaylibKey::LEFT) {
            velocity->_accelerationDirection.x += -1;
            std::cout << "LEFT Key" << std::endl;
        }
        if (keyPressed == Otter::Graphic::Raylib::RaylibKeyboard::RaylibKey::RIGHT) {
            velocity->_accelerationDirection.x += 1;
            std::cout << "RIGHT Key" << std::endl;
        }
        if (keyPressed == Otter::Graphic::Raylib::RaylibKeyboard::RaylibKey::UP) {
            velocity->_accelerationDirection.y += -1;
            std::cout << "UP Key" << std::endl;
        }
        if (keyPressed == Otter::Graphic::Raylib::RaylibKeyboard::RaylibKey::DOWN) {
            velocity->_accelerationDirection.y += 1;
            std::cout << "DOWN Key" << std::endl;
        }
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
                int keyPressed = 0;
                while ((keyPressed = keyboard->_keyboard.getKeyPressed()) != 0) {
                    if (player)
                        PlayerMovementEvent(velocity, keyPressed);
                }
            }
        }
    }

} // namespace Otter::Games::RType::System::Event
  // namespace Otter::Game::RType::System::Event