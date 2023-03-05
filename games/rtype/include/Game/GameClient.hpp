/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** GameClient
*/

#ifndef GAMECLIENT_HPP_
#define GAMECLIENT_HPP_

#include "Components.hpp"
#include "baseComponents.hpp"
#include "AnimationComponent.hpp"
#include "AnimationSystem.hpp"
#include "OtterCore.hpp"
#include "System.hpp"
#include "GameStatusSystem.hpp"
#include "WinSystem.hpp"
#include "GameOverSystem.hpp"

#include "InitBaseEntity.hpp"
#include "InitEnemy.hpp"
#include "InitInvisibleWall.hpp"
#include "InitMobs.hpp"
#include "InitObstacle.hpp"
#include "InitParallaxes.hpp"
#include "InitPlayer.hpp"

namespace Otter::Games::GameClient {
    namespace components = Otter::Games::RType::Components;
    namespace systems = Otter::Games::RType::System;
    namespace utils = Otter::Games::RType::Utils;

    void createEntityObj(Otter::Core::Orchestrator& ref);

    void registerComponents(Otter::Core::Orchestrator& ref);

    void registerSystems(Otter::Core::SystemManager& ref);
} // namespace Otter::Games::GameClient

#endif /* !GAMECLIENT_HPP_ */
