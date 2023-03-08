/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameServer
*/

#ifndef GAMESERVER_HPP_
#define GAMESERVER_HPP_

#include "CheckClientNbSystem.hpp"
#include "Components.hpp"
#include "GameStatusSystem.hpp"
#include "InitBaseEntityServer.hpp"
#include "OtterCore.hpp"
#include "System.hpp"
#include "LobbyComponent.hpp"

namespace Otter::Games::GameServer {
    namespace components = Otter::Games::RType::Components;
    namespace systems = Otter::Games::RType::System;
    namespace utils = Otter::Games::RType::Utils;

    void createEntityObj(Otter::Core::Orchestrator& ref);

    void registerComponents(Otter::Core::Orchestrator& ref);

    void registerSystems(Otter::Core::SystemManager& ref);

    void configureScripting(Otter::Scripting::ScriptingManager&);

} // namespace Otter::Games::GameServer

#endif /* !GAMESERVER_HPP_ */
