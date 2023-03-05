/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitParallaxes
*/

#ifndef INITPARALLAXES_HPP_
#define INITPARALLAXES_HPP_

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

#endif /* !INITPARALLAXES_HPP_ */
