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

    void CreateShot(Otter::Core::Orchestrator& ref, size_t playerIndex)
    {
        auto const& transforms = ref.get_components<Otter::Games::RType::Components::Transform>();
        auto& textures = ref.get_components<Otter::Games::RType::Components::Texture>();
        auto& shooters = ref.get_components<Otter::Games::RType::Components::Shooter>();
        if (playerIndex < transforms.size() && playerIndex < textures.size() && playerIndex < shooters.size() &&
            transforms[playerIndex] && textures[playerIndex] && shooters[playerIndex]) {
            auto const& transform = transforms[playerIndex];
            auto& texture = textures[playerIndex];
            auto& shooter = shooters[playerIndex];
            // TODO: add cooldown shot handler
            if ((shooter->_shotNbr > 0 || shooter->_shotNbr == -1 ) && shooter->_canShoot) {
                Otter::Core::Entity shot = ref.createEntity();
                ref.add_component(shot, Otter::Games::RType::Components::Texture(
                                            "../assets/projectile.gif",
                                            Otter::Graphic::Raylib::RaylibTexture("../assets/projectile.gif")));
                ref.add_component(shot,
                                  Otter::Games::RType::Components::Transform(
                                      3, 0,
                                      {transform->_position.x + (texture->_texture.getWidth() * transform->_scale),
                                       transform->_position.y}));
                ref.add_component(shot, Otter::Games::RType::Components::Render());
                ref.add_component(shot, Otter::Games::RType::Components::Shot(playerIndex));
                ref.add_component(shot, Otter::Games::RType::Components::Velocity(0, 5, {1, 0}, {1, 0}));
                ref.add_component(shot, Otter::Games::RType::Components::Obstacle(Otter::Games::RType::Components::ObstacleType::BULLET, "bullet"));
                if (shooter->_shotNbr != -1)
                    shooter->_shotNbr -= 1;
                // TODO: need to update the other fields into shooter component
            }
        }
    }

    void EventHandler(Otter::Core::Orchestrator& ref, size_t playerIndex, auto& velocity, auto& player,
                      Otter::Games::RType::Utils::EventState state)
    {
        if (player)
            PlayerMovementEvent(velocity, state);
        std::cout << state << std::endl;
        if (player && state == Otter::Games::RType::Utils::EventState::SHOOT) {
            CreateShot(ref, playerIndex);
        }
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
                        EventHandler(ref, i, velocity, player, (Otter::Games::RType::Utils::EventState)it->second);
                        // TODO: add keyboard management for other entities
                    }
                }
            }
        }
    }

} // namespace Otter::Games::RType::System::Event