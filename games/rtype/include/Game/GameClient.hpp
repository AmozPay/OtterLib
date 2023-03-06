/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameClient
*/

#ifndef GAMECLIENT_HPP_
#define GAMECLIENT_HPP_

#include "AnimationComponent.hpp"
#include "AnimationSystem.hpp"
#include "Components.hpp"
#include "GameOverSystem.hpp"
#include "GameStatusSystem.hpp"
#include "InitBaseEntity.hpp"
#include "InitEnemy.hpp"
#include "InitInvisibleWall.hpp"
#include "InitMobs.hpp"
#include "InitParallaxes.hpp"
#include "InitPlayer.hpp"
#include "InitPowerup.hpp"
#include "OtterCore.hpp"
#include "System.hpp"
#include "WinSystem.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameClient {
    namespace components = Otter::Games::RType::Components;
    namespace systems = Otter::Games::RType::System;
    namespace utils = Otter::Games::RType::Utils;

    void createEntityObj(Otter::Core::Orchestrator& ref);

    void registerComponents(Otter::Core::Orchestrator& ref);

    void registerSystems(Otter::Core::SystemManager& ref);

    void configureScripting(Otter::Scripting::ScriptingManager&);

} // namespace Otter::Games::GameClient

#endif /* !GAMECLIENT_HPP_ */
