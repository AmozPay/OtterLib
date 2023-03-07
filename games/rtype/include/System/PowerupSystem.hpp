/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PowerupSystem.hpp
*/

#ifndef RTYPE_PWOERUPSYSTEM_HPP
#define RTYPE_PWOERUPSYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Powerup {

    /**
     * @brief Powerup handler
     * @details Handle the powerup picked up by an entity
     * @param ref: The orchestrator
     * @param powerupId: The id of the powerup
     * @param pickedUpEntityId: The id of the entity that picked up the powerup
    */
    void PowerupHandler(Otter::Core::Orchestrator& ref, int powerupId, int pickedUpEntityId);

    /**
     * @brief Health powerup handler
     * @details Handle the health powerup picked up by an entity by increasing its health
     * @param ref: The orchestrator
     * @param powerup: The powerup
     * @param pickedUpEntityId: The id of the entity that picked up the powerup
    */
    void HealthPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId);

    /**
     * @brief Damage powerup handler
     * @details Handle the damage powerup picked up by an entity by decreasing its health
     * @param ref: The orchestrator
     * @param powerup: The powerup
     * @param pickedUpEntityId: The id of the entity that picked up the powerup
    */
    void DamagePowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId);

    /**
     * @brief Strength powerup handler
     * @details Handle the strength powerup picked up by an entity by increasing its damage
     * @param ref: The orchestrator
     * @param powerup: The powerup
     * @param pickedUpEntityId: The id of the entity that picked up the powerup
    */
    void StrengthPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId);

    /**
     * @brief Weakness powerup handler
     * @details Handle the weakness powerup picked up by an entity by decreasing its damage
     * @param ref: The orchestrator
     * @param powerup: The powerup
     * @param pickedUpEntityId: The id of the entity that picked up the powerup
    */
    void WeaknessPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId);

    /**
     * @brief Speed powerup handler
     * @details Handle the speed powerup picked up by an entity by increasing its speed
     * @param ref: The orchestrator
     * @param powerup: The powerup
     * @param pickedUpEntityId: The id of the entity that picked up the powerup
    */
    void SpeedPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId);

    /**
     * @brief Slowness powerup handler
     * @details Handle the slowness powerup picked up by an entity by decreasing its speed
     * @param ref: The orchestrator
     * @param powerup: The powerup
     * @param pickedUpEntityId: The id of the entity that picked up the powerup
    */
    void SlownessPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId);

}

#endif // RTYPE_PWOERUPSYSTEM_HPP