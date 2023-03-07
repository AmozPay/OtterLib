/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitEnemy
*/

#ifndef INITENEMY_HPP_
#define INITENEMY_HPP_

#include "Animation.hpp"
#include "AnimationComponent.hpp"
#include "Components.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameClient::Init {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    class InitEnemy {
      public:
        InitEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Games::RType::Utils::Vector2 pos);
        ~InitEnemy();

        void InitBasicEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Games::RType::Utils::Vector2 pos);

        void InitShootingEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Games::RType::Utils::Vector2 pos);

      protected:
      private:
    };
} // namespace Otter::Games::GameClient::Init

#endif /* !INITENEMY_HPP_ */
