/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitEnemy
*/

#ifndef INITENEMYCLIENT_HPP_
#define INITENEMYCLIENT_HPP_

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
        InitEnemy(
          Otter::Core::Orchestrator& ref,
          Otter::Core::Entity baseEntity,
          int id,
          Otter::Games::RType::Utils::Vector2 pos
        );
        ~InitEnemy();

      protected:
      private:
    };
} // namespace Otter::Games::GameClient::Init

#endif /* !INITENEMYCLIENT_HPP_ */
