/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitParallaxes
*/

#ifndef INITPARALLAXESCLIENT_HPP_
#define INITPARALLAXESCLIENT_HPP_

#include "OtterCore.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::GameClient::Init {
    class InitParallaxes {
      public:
        InitParallaxes(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity);
        ~InitParallaxes();

      protected:
      private:
    };
} // namespace Otter::Games::GameClient::Init

#endif /* !INITPARALLAXESCLIENT_HPP_ */
