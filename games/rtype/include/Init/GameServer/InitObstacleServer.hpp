/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitObstacle
*/

#ifndef INITOBSTACLESERVER_HPP_
#define INITOBSTACLESERVER_HPP_

#include "OtterCore.hpp"
#include "Components.hpp"
#include "baseComponents.hpp"
#include "Utils.hpp"

namespace Otter::Games::GameServer::Init
{
    namespace components = Otter::Games::RType::Components;

    class InitObstacle {
        public:
            InitObstacle(
                Otter::Core::Orchestrator& ref,
                Otter::Core::Entity baseEntity
            );
            ~InitObstacle();

        protected:
        private:
    };
}

#endif /* !INITOBSTACLESERVER_HPP_ */
