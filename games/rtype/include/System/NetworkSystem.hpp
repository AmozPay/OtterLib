/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** NetworkSystem
*/

#ifndef NETWORKSYSTEM_HPP_
#define NETWORKSYSTEM_HPP_

#include "OtterCore.hpp"

namespace Otter::Games::RType::System::Network {

    /**
     * @brief Init nework
     * @details lunch thread and io contex
     * @warning if used in other pahse that init, unknwo behave
     */
    void initNetwork(Otter::Core::Orchestrator& ref);

    /**
     * @brief Get All Network Updated Value
     * @details Get All Network Updated Value from the server or client
     * @param ref: The orchestrator
     * @return void
     */
    void getAllNetworkUpdatedValue(Otter::Core::Orchestrator& ref);

    /**
     * @brief Send All Network Updated Value
     * @details Send All Network Updated Value to the server or client
     * @param ref: The orchestrator
     * @return void
     */
    void sendAllNetworkUpdatedValue(Otter::Core::Orchestrator& ref);
} // namespace Otter::Games::RType::System::Network

#endif /* !NETWORKSYSTEM_HPP_ */
