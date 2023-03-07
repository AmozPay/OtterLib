/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitBoss
*/

#ifndef INITBOSS_HPP_
#define INITBOSS_HPP_

#include "Animation.hpp"
#include "AnimationComponent.hpp"
#include "Components.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameClient::Init {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    class InitBoss {
        public:
            InitBoss(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                    Otter::Games::RType::Utils::Vector2 pos);
            ~InitBoss();

        protected:
        private:
    };

}

#endif /* !INITBOSS_HPP_ */
