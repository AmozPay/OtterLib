/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitBaseEntity
*/

#ifndef INITBASEENTITY_HPP_
#define INITBASEENTITY_HPP_

#include "OtterCore.hpp"
#include "Components.hpp"
#include "baseComponents.hpp"
#include "AnimationComponent.hpp"
#include "Utils.hpp"
#include "Animation.hpp"
#include "System.hpp"
#include "LobbySystem.hpp"
#include "InitGameSystem.hpp"

namespace Otter::Games::GameClient::Init
{
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;
    namespace systems = Otter::Games::RType::System;

    class InitBaseEntity {
        public:
            InitBaseEntity(Otter::Core::Orchestrator& ref);
            ~InitBaseEntity();
            Otter::Core::Entity getEntity() const;

        private:
            Otter::Core::Entity baseEntity;

    };

}

#endif /* !INITBASEENTITY_HPP_ */
