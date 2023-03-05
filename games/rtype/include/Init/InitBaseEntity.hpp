/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitBaseEntity
*/

#ifndef INITBASEENTITY_HPP_
#define INITBASEENTITY_HPP_

#include "Animation.hpp"
#include "AnimationComponent.hpp"
#include "Components.hpp"
#include "GameOverSystem.hpp"
#include "InitGameSystem.hpp"
#include "LobbySystem.hpp"
#include "OtterCore.hpp"
#include "System.hpp"
#include "Utils.hpp"
#include "WinSystem.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameClient::Init {
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

} // namespace Otter::Games::GameClient::Init

#endif /* !INITBASEENTITY_HPP_ */
