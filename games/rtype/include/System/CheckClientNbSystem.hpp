/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** CheckClientNbSystem
*/

#ifndef CHECKCLIENTNBSYSTEM_HPP_
#define CHECKCLIENTNBSYSTEM_HPP_

#include "OtterCore.hpp"
#include "OtterNetwork.hpp"
#include "ServerComponent.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::CheckClientNb {

    /**
     * @brief System for sprites animation
     * @details Move sprite rect for 2d animation
     * @param ref: The orchestrator
     * @return void
     */
    void CheckClientNb(Otter::Core::Orchestrator& ref);

} // namespace Otter::Games::RType::System::CheckClientNb

#endif /* !CHECKCLIENTNBSYSTEM_HPP_ */
