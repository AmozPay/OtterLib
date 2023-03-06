/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventNetworkSystem.hpp
*/

#ifndef RTYPE_INPUTKEYEVENTSYSTEM_HPP
#define RTYPE_INPUTKEYEVENTSYSTEM_HPP

#include "OtterCore.hpp"
#include "Utils.hpp"

namespace Otter::Games::RType::System::InputKeyEventSystem {

    namespace utils = Otter::Games::RType::Utils;

    /**
     * @brief Player movement event
     * @details Update the velocity of the player
     * @param velocity: The velocity of the player
     * @param state: The state of the event
     * @return void
     */
    void PlayerMovementEvent(auto& velocity, utils::EventState state);

    /**
     * @brief Create a Shot Entity object
     * @details Create a Shot Entity object
     * @param ref: The orchestrator
     * @param playerIndex: The player index
     * @param transform: The transform of the player
     * @param texture: The texture of the player
     * @param shooter: The shooter component of the player
     * @return void
     */
    void CreateShotEntity(Otter::Core::Orchestrator& ref, size_t playerIndex, auto const& transform, auto& texture,
                          auto& shooter);

    /**
     * @brief Create a Shot object
     * @details Create a Shot object
     * @param ref: The orchestrator
     * @param playerIndex: The player index
     * @return void
     */
    void CreateShot(Otter::Core::Orchestrator& ref, size_t playerIndex);

    /**
     * @brief Detect the event
     * @details Detect the event and manage events
     * @param ref: The orchestrator
     * @param playerIndex: The player index
     * @param state: The state of the event
     * @return void
     */
    void EventDetection(Otter::Core::Orchestrator& ref, size_t playerIndex, utils::EventState state);

    /**
     * @brief Get the event
     * @details Get the event and manage events
     * @param ref: The orchestrator
     * @return void
     */
    void EventHandler(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::InputKeyEventSystem

#endif // RTYPE_INPUTKEYEVENTSYSTEM_HPP