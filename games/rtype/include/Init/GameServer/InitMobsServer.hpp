/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitMobs
*/

#ifndef INITMOBSSERVER_HPP_
#define INITMOBSSERVER_HPP_

#include "AnimationComponent.hpp"
#include "AnimationSystem.hpp"
#include "Components.hpp"
#include "OtterCore.hpp"
#include "System.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameServer::Init {

    class InitMobs {
      public:
        InitMobs(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity);
        ~InitMobs();

      protected:
      private:
    };
} // namespace Otter::Games::GameServer::Init

#endif /* !INITMOBSSERVER_HPP_ */
