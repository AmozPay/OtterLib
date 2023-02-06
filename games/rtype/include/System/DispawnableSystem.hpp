/*
** EPITECH PROJECT, 2023
** RType
** File description:
** DispawnableSystem.hpp
*/

#ifndef RTYPE_DISPAWNABLESYSTEM_HPP
#define RTYPE_DISPAWNABLESYSTEM_HPP

#include "Components.hpp"
#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Dispawnable {

    /**
     * @brief System for the dispawn of the entities
     * @details The dispawn system is used to dispawn the entities based on their transform component
     * @param ref: The orchestrator
     * @return void
     */
    void EntityDispawn(Otter::Core::Orchestrator& ref);
} // namespace Otter::Games::RType::System::Dispawnable

#endif // RTYPE_DISPAWNABLESYSTEM_HPP