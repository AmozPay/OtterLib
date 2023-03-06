/*
** EPITECH PROJECT, 2023
** RType
** File description:
** PowerupSystem.cpp
*/

#include "PowerupSystem.hpp"
#include "OtterCore.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::Powerup {

    namespace core = Otter::Core;
    namespace components = Otter::Games::RType::Components;

    void PowerupHandler(Otter::Core::Orchestrator& ref, int powerupId, int pickedUpEntityId) {
        const auto& powerups = ref.get_components<components::Powerup>();

        if (powerupId < powerups.size() && powerups[powerupId]) {
            const auto& powerup = powerups[powerupId];

            if (powerup->_type == components::HEALTH)
                HealthPowerupHandler(ref, powerup, pickedUpEntityId);
            if (powerup->_type == components::DAMAGE)
                DamagePowerupHandler(ref, powerup, pickedUpEntityId);
            if (powerup->_type == components::STRENGTH)
                StrengthPowerupHandler(ref, powerup, pickedUpEntityId);
            if (powerup->_type == components::WEAKNESS)
                WeaknessPowerupHandler(ref, powerup, pickedUpEntityId);
            if (powerup->_type == components::SPEED)
                SpeedPowerupHandler(ref, powerup, pickedUpEntityId);
            if (powerup->_type == components::SLOWNESS)
                SlownessPowerupHandler(ref, powerup, pickedUpEntityId);

            ref.remove_entity(powerupId);
        }
    }

    void HealthPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId) {
        auto& healths = ref.get_components<core::BaseComponents::Health>();

        if (pickedUpEntityId < healths.size() && healths[pickedUpEntityId]) {
            auto& health = healths[pickedUpEntityId];

            health->_hp += powerup->_value;
            std::cout << health->_hp << std::endl;
        }
    }

    void DamagePowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId) {
        auto& healths = ref.get_components<core::BaseComponents::Health>();

        if (pickedUpEntityId < healths.size() && healths[pickedUpEntityId]) {
            auto& health = healths[pickedUpEntityId];

            health->_hp -= powerup->_value;
            std::cout << health->_hp << std::endl;
        }
    }

    void StrengthPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId) {
        auto& damages = ref.get_components<core::BaseComponents::Damage>();

        if (pickedUpEntityId < damages.size() && damages[pickedUpEntityId]) {
            auto& damage = damages[pickedUpEntityId];

            damage->_damage += powerup->_value;
            std::cout << damage->_damage << std::endl;
        }
    }

    void WeaknessPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId) {
        auto& damages = ref.get_components<core::BaseComponents::Damage>();

        if (pickedUpEntityId < damages.size() && damages[pickedUpEntityId]) {
            auto& damage = damages[pickedUpEntityId];

            if (powerup->_value > damage->_damage)
                damage->_damage = 0;
            else
                damage->_damage -= powerup->_value;
                std::cout << damage->_damage << std::endl;
        }
    }

    void SpeedPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId) {
        auto& velocities = ref.get_components<core::BaseComponents::Velocity>();

        if (pickedUpEntityId < velocities.size() && velocities[pickedUpEntityId]) {
            auto& velocity = velocities[pickedUpEntityId];

            velocity->_speed += powerup->_value;
            std::cout << velocity->_speed << std::endl;
        }
    }

    void SlownessPowerupHandler(Otter::Core::Orchestrator& ref, const auto& powerup, int pickedUpEntityId) {
        auto& velocities = ref.get_components<core::BaseComponents::Velocity>();

        if (pickedUpEntityId < velocities.size() && velocities[pickedUpEntityId]) {
            auto& velocity = velocities[pickedUpEntityId];

            velocity->_speed -= powerup->_value;
            std::cout << velocity->_speed << std::endl;
        }
    }

}