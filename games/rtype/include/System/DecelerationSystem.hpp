/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** DecelerationSystem
*/

#ifndef DECELERATIONSYSTEM_HPP_
#define DECELERATIONSYSTEM_HPP_

#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Deceleration {

    /**
     * @brief System for the deceleration of the entities
     * @details The deceleration system apply a deceleration to the entities
     * @param ref: The orchestrator
     * @return void
    */
    void Deceleration(Otter::Core::Orchestrator& ref);

}
#endif /* !DECELERATIONSYSTEM_HPP_ */
