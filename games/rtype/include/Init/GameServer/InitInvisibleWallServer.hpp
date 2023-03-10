/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitInvisibleWall
*/

#ifndef INITINVISIBLEWALLSERVER_HPP_
#define INITINVISIBLEWALLSERVER_HPP_

#include "Components.hpp"
#include "OtterCore.hpp"
#include "Utils.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameServer::Init {
    namespace components = Otter::Games::RType::Components;

    class InitInvisibleWall {
      public:
        InitInvisibleWall(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity);
        ~InitInvisibleWall();

      protected:
      private:
    };
} // namespace Otter::Games::GameServer::Init

#endif /* !INITINVISIBLEWALLSERVER_HPP_ */
