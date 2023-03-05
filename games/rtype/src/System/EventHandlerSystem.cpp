/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** EventHandlerSystem
*/

#include "EventHandlerSystem.hpp"

#include "EventComponent.hpp"

namespace Otter::Games::RType::System::EventHandler {
    using EventHandlerComponent = Otter::Games::RType::Components::EventHandlerComponent;
    using EventComponent = Otter::Games::RType::Components::EventComponent;
    using EventPairList = Otter::Games::RType::Components::EventPairList;

    void handleEvents(Otter::Core::Orchestrator& ref, EventHandlerComponent& eventHandlerComponent,
                      EventComponent& eventsComponent)
    {
        EventPairList::iterator it = eventsComponent.events.begin();

        while (it != eventsComponent.events.end()) {
            eventHandlerComponent.handleEvent(ref, it->first, it->second);
            it++;
            eventsComponent.events.pop_front();
        }
    }

    void EventHandlerSystem(Otter::Core::Orchestrator& ref)
    {
        auto& eventsHandlers = ref.get_components<Otter::Games::RType::Components::EventHandlerComponent>();
        auto& events = ref.get_components<Otter::Games::RType::Components::EventComponent>();

        for (std::size_t x = 0; x < eventsHandlers.size(); x++) {
            if (!eventsHandlers[x])
                continue;
            for (std::size_t y = 0; y < events.size(); y++) {
                if (!events[y])
                    continue;
                handleEvents(ref, *eventsHandlers[x], *events[y]);
            }
        }
    }

} // namespace Otter::Games::RType::System::EventHandler
