/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitEnemy
*/

#ifndef INITENEMYSERVER_HPP_
#define INITENEMYSERVER_HPP_

#include "Animation.hpp"
#include "AnimationComponent.hpp"
#include "Components.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameServer::Init {
    namespace components = Otter::Games::RType::Components;

    class InitEnemy {
      public:
        InitEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Core::Utils::Vector2 pos);
        ~InitEnemy();

        void InitBasicEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Core::Utils::Vector2 pos);

        void InitShootingEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Core::Utils::Vector2 pos);

      protected:
      private:
    };
} // namespace Otter::Games::GameServer::Init

#endif /* !INITENEMYSERVER_HPP_ */
