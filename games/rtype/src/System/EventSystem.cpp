/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventSystem.cpp
*/

#include "EventSystem.hpp"

#include "Components.hpp"
#include "OtterGraphic.hpp"

namespace Otter::Game::RType::System::Event {

    void PlayerMovementEvent(auto& velocity, int keyPressed)
    {
        if (keyPressed == Otter::Graphic::Raylib::RaylibKeyboard::RaylibKey::LEFT)
            velocity->accelerationDirection.x += -1;
        if (keyPressed == Otter::Graphic::Raylib::RaylibKeyboard::RaylibKey::RIGHT)
            velocity->accelerationDirection.x += 1;
        if (keyPressed == Otter::Graphic::Raylib::RaylibKeyboard::RaylibKey::UP)
            velocity->accelerationDirection.y += -1;
        if (keyPressed == Otter::Graphic::Raylib::RaylibKeyboard::RaylibKey::DOWN)
            velocity->accelerationDirection.y += 1;
    }

    void PollEvent(Otter::Core::Orchestrator& ref)
    {
        auto const& players = ref.get_components<Otter::Games::RType::Components::Player>();
        auto& velocities = ref.get_components<Otter::Games::RType::Components::Velocity>();
        auto const& keyboards = ref.get_components<Otter::Games::RType::Components::Keyboard>();
        for (size_t i = 0; i < players.size() && i < velocities.size() && i < keyboards.size(); i++) {
            auto const& player = players[i];
            auto& velocity = velocities[i];
            auto const& keyboard = keyboards[i];
            if (velocity && keyboard) {
                int keyPressed = 0;
                while ((keyPressed = keyboard->keyboard.getKeyPressed()) != 0) {
                    if (player)
                        PlayerMovementEvent(velocity, keyPressed);
                }
            }
        }
    }

} // namespace Otter::Game::RType::System::Event