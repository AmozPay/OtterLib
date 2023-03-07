/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventNetworkSystem.cpp
*/

#include "InputKeyEventSystem.hpp"
#include "ShotSystem.hpp"

#include "Components.hpp"
#include "baseComponents.hpp"

#include <chrono>

namespace Otter::Games::RType::System::InputKeyEventSystem {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;
    namespace raylib = Otter::Graphic::Raylib;

    void PlayerMovementEvent(Otter::Core::Orchestrator& ref, size_t playerIndex, utils::EventState state)
    {
        auto& velocities = ref.get_components<Otter::Core::BaseComponents::Velocity>();
        if (playerIndex < velocities.size() && velocities[playerIndex]) {
            auto& velocity = velocities[playerIndex];
            if (state == utils::EventState::BACKWARD)
                velocity->_accelerationDirection.x += -1;
            if (state == utils::EventState::FORWARD)
                velocity->_accelerationDirection.x += 1;
            if (state == utils::EventState::UP)
                velocity->_accelerationDirection.y += -1;
            if (state == utils::EventState::DOWN)
                velocity->_accelerationDirection.y += 1;
        }
    }

    void EventDetection(Otter::Core::Orchestrator& ref, size_t playerIndex, utils::EventState state)
    {
        PlayerMovementEvent(ref, playerIndex, state);
        if (state == utils::SHOOT)
            Otter::Games::RType::System::Shot::CreateShot(ref, playerIndex, false);
        if (state == utils::CLOSE) {
            // DO NOTHING FOR THE MOMENT
        }
    }

    void EventHandler(Otter::Core::Orchestrator& ref)
    {
        auto const& players = ref.get_components<Otter::Core::BaseComponents::Player>();
        auto& eventNetworks = ref.get_components<Otter::Core::BaseComponents::EventNetwork>();

        for (size_t i = 0; i < eventNetworks.size() && i < players.size(); i++) {
            auto& eventNetwork = eventNetworks[i];
            auto const& player = players[i];

            if (player && eventNetwork)
                EventDetection(ref, i, static_cast<utils::EventState>(eventNetwork->_data));
            eventNetwork->_data = -1;
        }
    }

} // namespace Otter::Games::RType::System::InputKeyEventSystem