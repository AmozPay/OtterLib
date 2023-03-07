/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** EventComponent
*/

#ifndef EVENTCOMPONENT_HPP_
#define EVENTCOMPONENT_HPP_

#include "OtterCore.hpp"

#include <functional>
#include <list>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Otter::Games::RType::Components {
    /**
     * @brief Custom events types
     * @enum EventTypes
     */
    enum EventTypes { LOBBY, INIT_LOBBY, INIT_GAME, COLISION, DEATH, GAME_OVER, WIN, RESET_GAME };

    using Orchestrator = Otter::Core::Orchestrator;
    using ComponentIdVector = std::vector<std::size_t>;
    using EventSystemFunc = std::function<void(Orchestrator&, ComponentIdVector&)>;
    using EventHandlerMap = std::unordered_map<EventTypes, EventSystemFunc>;
    using EventPair = std::pair<EventTypes, ComponentIdVector>;
    using EventPairList = std::list<EventPair>;

    /**
     * @brief Component for handling events
     * @details The goal of this component is to register
     * handling function for custom events type. Be carfull
     * This component need to be registered only one time.
     * @struct EventHandlerComponent
     */
    struct EventHandlerComponent {
        EventHandlerComponent(const EventHandlerMap& eventHandlerMap) { this->eventHandlerMap = eventHandlerMap; };

        ~EventHandlerComponent(){};

        void handleEvent(Orchestrator& ref, const EventTypes& eventType, ComponentIdVector& componentIdVector)
        {
            EventHandlerMap::iterator it = eventHandlerMap.find(eventType);

            if (it == eventHandlerMap.end())
                return;
            it->second(ref, componentIdVector);
        };

        EventHandlerMap eventHandlerMap;
    };

    /**
     * @brief Component for saving new Event
     * @details The goal of this component is to register
     * events when you need to trigger it. Be carfull
     * This component need to be registered only one time.
     * @struct EventComponent
     */
    struct EventComponent {
        EventComponent(){};
        ~EventComponent(){};

        EventPairList events;
    };

} // namespace Otter::Games::RType::Components

#endif /* !EVENTCOMPONENT_HPP_ */
