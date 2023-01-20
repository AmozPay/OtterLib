#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H
#include "Orchestrator.hpp"
#include <functional>
#include <iostream>
#include <vector>
namespace Core {

class Orchestrator;
class SystemManager {
  public:
    SystemManager() : _systems(){};
    ~SystemManager(){};

    template <typename F> void register_system(F &&function) {
        auto f = [&function](Core::Orchestrator &reg) { function(reg); };
        _systems.push_back(std::function(f));
    }

    void run_systems(Core::Orchestrator &reg) {
        for (auto const &it : _systems) {
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

    std::vector<std::function<void(Core::Orchestrator &)>> _systems;
};

} // namespace Core

#endif /* SYSTEMMANAGER_H */
