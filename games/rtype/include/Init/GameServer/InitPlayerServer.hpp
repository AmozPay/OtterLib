/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitPlayer
*/

#ifndef INITPLAYERSERVER_HPP_
#define INITPLAYERSERVER_HPP_

#include "Components.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameServer::Init {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    class InitPlayer {
      public:
        InitPlayer(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity);
        ~InitPlayer();

      protected:
      private:
    };
} // namespace Otter::Games::GameServer::Init

#endif /* !INITPLAYERSERVER_HPP_ */
