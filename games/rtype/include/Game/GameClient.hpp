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
#include "InitBaseEntityClient.hpp"
#include "InitEnemyClient.hpp"
#include "InitInvisibleWallClient.hpp"
#include "InitMobsClient.hpp"
#include "InitObstacleClient.hpp"
#include "InitParallaxesClient.hpp"
#include "InitPlayerClient.hpp"
#include "System.hpp"

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
