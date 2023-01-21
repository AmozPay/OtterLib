#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H
#include "Orchestrator.hpp"

#include <functional>
#include <iostream>
#include <vector>

namespace Otter::Core {

    class Orchestrator;

    /**
     * @class SystemManager
     *
     * @brief class who store and call system.
     *
     * @warning Feathure actuali 1.0 can't store complex system
     */
    class SystemManager {
      public:
      SystemManager() : _systems() {};
        ~SystemManager(){};

        /**
         * @brief Function for register system
         * @param A function lvalue or rvalue
         * @warning Feathure actuali 1.0 can't store complex system
         */
        template <typename F>
        void registerSystem(F&& function)
        {
            auto f = [&function](Core::Orchestrator& reg) { function(reg); };
            _systems.push_back(std::function(f));
        }

      void operator()(Otter::Core::Orchestrator &ref, std::string phase, float time = 0)
      {
	this->run_systems(ref);

      }
        /**
         * @brief Exec all system
         *
         * @details excution donne in the same order as the registering
         * @param lvalue to a orchestrator.
         */
        void run_systems(Core::Orchestrator& reg)
        {
            for (auto const& it : _systems) {
                it(reg);
            }
        }

      private:
        /*
        template<class ...C, typename U>
        U binding_func(C... component, U func);

        template<typename T, class ...Comp, typename U>
        U binding_func(T t, C...component, U func) {

          return binding_func(component, std::bind
        }

        template<typename U>
        U binding_func(U func) {
          reutrn func;
          }*/
        std::vector<std::function<void(Core::Orchestrator&)>> _systems;
    };

} // namespace Otter::Core

#endif /* SYSTEMMANAGER_H */
