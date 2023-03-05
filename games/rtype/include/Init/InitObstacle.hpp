/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitObstacle
*/

#ifndef INITOBSTACLE_HPP_
#define INITOBSTACLE_HPP_

#include "Components.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameClient::Init {
    namespace components = Otter::Games::RType::Components;

    class InitObstacle {
      public:
        InitObstacle(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity);
        ~InitObstacle();

      protected:
      private:
    };
} // namespace Otter::Games::GameClient::Init

#endif /* !INITOBSTACLE_HPP_ */
