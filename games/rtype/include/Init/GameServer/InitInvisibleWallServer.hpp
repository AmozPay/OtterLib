/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitInvisibleWall
*/

#ifndef INITINVISIBLEWALLSERVER_HPP_
#define INITINVISIBLEWALLSERVER_HPP_

#include "OtterCore.hpp"
#include "Components.hpp"
#include "baseComponents.hpp"
#include "Utils.hpp"

namespace Otter::Games::GameServer::Init
{
    namespace components = Otter::Games::RType::Components;

    class InitInvisibleWall {
        public:
            InitInvisibleWall(
                Otter::Core::Orchestrator& ref,
                Otter::Core::Entity baseEntity
            );
            ~InitInvisibleWall();

        protected:
        private:
    };
}

#endif /* !INITINVISIBLEWALLSERVER_HPP_ */
