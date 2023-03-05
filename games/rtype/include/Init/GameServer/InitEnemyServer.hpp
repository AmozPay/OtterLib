/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitEnemy
*/

#ifndef INITENEMYSERVER_HPP_
#define INITENEMYSERVER_HPP_

#include "OtterCore.hpp"
#include "Components.hpp"
#include "baseComponents.hpp"
#include "AnimationComponent.hpp"
#include "Utils.hpp"
#include "Animation.hpp"

namespace Otter::Games::GameServer::Init
{
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    class InitEnemy {
        public:
            InitEnemy(
                Otter::Core::Orchestrator& ref,
                Otter::Core::Entity baseEntity,
                std::string id,
                Otter::Games::RType::Utils::Vector2 pos
            );
            ~InitEnemy();

        protected:
        private:
    };
}

#endif /* !INITENEMYSERVER_HPP_ */
