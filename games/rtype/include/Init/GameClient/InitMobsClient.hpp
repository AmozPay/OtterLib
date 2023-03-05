/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitMobs
*/

#ifndef INITMOBS_HPPCLIENT_
#define INITMOBS_HPPCLIENT_

#include "Components.hpp"
#include "AnimationComponent.hpp"
#include "AnimationSystem.hpp"
#include "OtterCore.hpp"
#include "System.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameClient::Init
{

    class InitMobs {
        public:
            InitMobs(
                Otter::Core::Orchestrator& ref,
                Otter::Core::Entity baseEntity
            );
            ~InitMobs();

        protected:
        private:
    };
}

#endif /* !INITMOBS_HPPCLIENT_ */
