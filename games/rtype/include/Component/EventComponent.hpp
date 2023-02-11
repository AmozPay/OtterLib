/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** EventComponent
*/

#ifndef EVENTCOMPONENT_HPP_
#define EVENTCOMPONENT_HPP_

#include <list>
#include <utility>
#include <functional>
#include <vector>
#include <string>
#include <unordered_map>
#include "OtterCore.hpp"

namespace Otter::Games::RType::Components {
    using Orchestrator = Otter::Core::Orchestrator;
    using ComponentIdVector = std::vector<std::string>;
    using EventSystemFunc = std::function<void(Orchestrator&, ComponentIdVector&)>;
    using EventHandlerPair = std::pair<EventTypes, EventSystemFunc>;
    using EventHandlerPairList = std::list<EventHandlerPair>;
    using EventHandlerMap = std::unordered_map<EventTypes, EventSystemFunc>;

    enum EventTypes {
        COLISION,
        DEATH,
    };

    struct EventHandlerComponent
    {
        EventHandlerComponent(const EventHandlerMap &eventHandlerMap)
        {
            this->eventHandlerMap = eventHandlerMap;
        };

        void handleEvent(
            const EventTypes &eventType,
            Orchestrator& ref,
            ComponentIdVector& componentIdVector
        )
        {
            EventHandlerMap::iterator it = eventHandlerMap.find(eventType);

            if (it == eventHandlerMap.end())
                return;
            it->second(ref, componentIdVector);
        };

        EventHandlerMap eventHandlerMap;
    };
}


#endif /* !EVENTCOMPONENT_HPP_ */
