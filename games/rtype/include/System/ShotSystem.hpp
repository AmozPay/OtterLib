/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** ShotSystem
*/

#ifndef SHOTSYSTEM_HPP_
#define SHOTSYSTEM_HPP_

#include "OtterCore.hpp"
#include "Components.hpp"

namespace Otter::Games::RType::System::Shot {

    enum ShooterType { PLAYER, ENEMY, BOSS };

    /**
     * @brief Create a Shot Entity object for the player
     * @details Create a Shot Entity object
     * @param ref: The orchestrator
     * @param playerIndex: The player index
     * @param transform: The transform of the player
     * @param texture: The texture of the player
     * @param shooter: The shooter component of the player
     * @return void
     */
    void CreatePlayerShotEntity(Otter::Core::Orchestrator& ref, size_t playerIndex, auto const& transform, auto& texture,
                          auto& shooter);

    /**
     * @brief Create a Shot Entity object for the enemy
     * @details Create a Shot Entity object
     * @param ref: The orchestrator
     * @param enemyIndex: The enemy index
     * @param transform: The transform of the enemy
     * @param texture: The texture of the enemy
     * @param shooter: The shooter component of the enemy
     * @return void
     */
    void CreateEnemyShotEntity(Otter::Core::Orchestrator& ref, size_t enemyIndex, auto const& transform, auto& texture,
                          auto& shooter);

    /**
     * @brief Create a Shot object
     * @details Create a Shot object
     * @param ref: The orchestrator
     * @param playerIndex: The player index
     * @param isEnemy: True if the shooting entity is an enemy (false otherwise)
     * @return void
     */
    void CreateShot(Otter::Core::Orchestrator& ref, size_t playerIndex, ShooterType shooterType);

}

#endif /* !SHOTSYSTEM_HPP_ */
