/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameClient
*/

#ifndef GAMECLIENT_HPP_
#define GAMECLIENT_HPP_

#include "Components.hpp"
#include "OtterCore.hpp"
#include "System.hpp"

namespace Otter::Games::GameClient {
    namespace components = Otter::Games::RType::Components;
    namespace systems = Otter::Games::RType::System;
    namespace utils = Otter::Games::RType::Utils;

    void createEntityObj(Otter::Core::Orchestrator& ref);

    void registerComponents(Otter::Core::Orchestrator& ref);

    void registerSystems(Otter::Core::SystemManager& ref);
} // namespace Otter::Games::GameClient

#endif /* !GAMECLIENT_HPP_ */
