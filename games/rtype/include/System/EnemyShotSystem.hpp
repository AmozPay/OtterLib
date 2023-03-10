/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EnemyShotSystem.hpp
*/

#ifndef RTYPE_ENEMYSHOTSYSTEM_HPP
#define RTYPE_ENEMYSHOTSYSTEM_HPP

#include "AnimationComponent.hpp"
#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::EnemyShot {

    /**
     * @brief Automatic shot for an entity
     * @details Automatic shot for an entity
     * @param ref: The orchestrator
     * @return void
    */
    void AutomaticShotForEntity(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::EnemyShot

#endif // RTYPE_ENEMYSHOTSYSTEM_HPP