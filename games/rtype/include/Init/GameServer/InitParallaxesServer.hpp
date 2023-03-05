/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitParallaxes
*/

#ifndef INITPARALLAXESSERVER_HPP_
#define INITPARALLAXESSERVER_HPP_

#include "OtterCore.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameServer::Init
{
    class InitParallaxes {
        public:
            InitParallaxes(
                Otter::Core::Orchestrator& ref,
                Otter::Core::Entity baseEntity
            );
            ~InitParallaxes();

        protected:
        private:
    };
}

#endif /* !INITPARALLAXESSERVER_HPP_ */
