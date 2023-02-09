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
        enum Phase {
            init,
            preEvent,
            event,
            preUpdate,
            update,
            preDraw,
            draw,
            subDraw,
            end,
        };

        using sysList = std::vector<std::function<void(Core::Orchestrator&)>>;
        using phase_map = std::vector<sysList>;

      public:
        SystemManager() : _systems()
        {
            for (int i = 0; i <= Phase::end; i++) {
                _systems.push_back(sysList());
            }
        };

        ~SystemManager(){};

        /**
         * @brief Function for register system
         * @param A function lvalue or rvalue
         * @warning Feathure actuali 1.0 can't store complex system
         */
        template <typename F>
        void registerSystem(F&& function, SystemManager::Phase phase)
        {
            auto f = [&function](Core::Orchestrator& reg) { function(reg); };
            _systems[phase].push_back(std::function(f));
        }

        /**
         * @brief Exec all system by phase
         *
         * @details excution done by phase in the order of registering
         * @param lvalue to a orchestrator.
         * @param enum phase at wich time is execute
         */
        void operator()(Otter::Core::Orchestrator& ref, SystemManager::Phase phase)
        {
            for (auto const& it : _systems[phase]) {
                it(ref);
            }
        }

      private:
        // update update_fix

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
        phase_map _systems;
    };

} // namespace Otter::Core

#endif /* SYSTEMMANAGER_H */
