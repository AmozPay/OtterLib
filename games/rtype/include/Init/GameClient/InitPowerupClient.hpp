/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitPowerup
*/

#ifndef INITOBSTACLE_HPP_
#define INITOBSTACLE_HPP_

#include "Components.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameClient::Init {
    namespace components = Otter::Games::RType::Components;

    class InitPowerup {
      public:
        InitPowerup(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                  Otter::Games::RType::Utils::Vector2 pos, Otter::Games::RType::Components::PowerupType powerupType, int powerupValue);
        ~InitPowerup();

      protected:
      private:
    };
} // namespace Otter::Games::GameClient::Init

#endif /* !INITPOWERUP_HPP_ */
