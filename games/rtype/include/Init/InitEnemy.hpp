/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitEnemy
*/

#ifndef INITENEMY_HPP_
#define INITENEMY_HPP_

#include "OtterCore.hpp"
#include "Components.hpp"
#include "baseComponents.hpp"
#include "AnimationComponent.hpp"
#include "Utils.hpp"
#include "Animation.hpp"

namespace Otter::Games::GameClient::Init
{
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    class InitEnemy {
        public:
            InitEnemy(
                Otter::Core::Orchestrator& ref,
                Otter::Core::Entity baseEntity
            );
            ~InitEnemy();

        protected:
        private:
    };
}

#endif /* !INITENEMY_HPP_ */
