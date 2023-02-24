/*
** EPITECH PROJECT, 2023
** RType
** File description:
** DeathSystem.hpp
*/

#ifndef RTYPE_DEATHSYSTEM_HPP
#define RTYPE_DEATHSYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Death {

    /**
     * @brief System for the death of the entities
     * @details The death system is used to check if the entities are dead
     * @param ref: The orchestrator
     * @return void
     */
    void EntityDeath(Otter::Core::Orchestrator& ref);

    /**
     * @brief Trigger the death event
     * @details This function is used to trigger the death event
     * @param ref: The orchestrator
     * @param entityIndex: The index of the dead entity
     * @return void
     */
    void TriggerDeath(Otter::Core::Orchestrator& ref, size_t entityIndex);

    /**
     * @brief Handle the death event
     * @details This function is used to handle the death event
     * @param ref: The orchestrator
     * @param vectorId: The vector of the ids of the entities
     * @return void
     */
    void HandleDeath(Otter::Core::Orchestrator& ref, std::vector<std::size_t>& vectorId);

} // namespace Otter::Games::RType::System::Death

#endif // RTYPE_DEATHSYSTEM_HPP