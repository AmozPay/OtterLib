/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem.cpp
*/

#include "EventCollisionSystem.hpp"

namespace Otter::Games::RType::System::Collision {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    void TriggerCollision(Otter::Core::Orchestrator& ref, size_t firstEntityIndex, size_t secondEntityIndex)
    {
        auto& events = ref.get_components<components::EventComponent>();

        for (size_t i = 0; i < events.size(); i++) {
            auto& event = events[i];
            if (event) {
                components::EventPair eventPair(components::EventTypes::COLISION,
                                                components::ComponentIdVector({firstEntityIndex, secondEntityIndex}));
                event->events.push_back(eventPair);
            }
        }
    }

    void SecondEntityCollision(Otter::Core::Orchestrator& ref, auto& collisions, auto& transforms,
                               size_t firstEntityIndex)
    {
        for (size_t i = 0; i < collisions.size() && i < transforms.size(); i++) {
            if (i == firstEntityIndex)
                continue;
            auto& collisionsSecond = collisions[i];
            auto& transformSecond = transforms[i];
            if (collisionsSecond && transformSecond) {
                utils::Rectangle rectangleFirst = {
                    transforms[firstEntityIndex]->_position.x, transforms[firstEntityIndex]->_position.y,
                    collisions[firstEntityIndex]->_width, collisions[firstEntityIndex]->_height};
                utils::Rectangle rectangleSecond = {transforms[i]->_position.x, transforms[i]->_position.y,
                                                    collisionsSecond->_width, collisionsSecond->_height};
                if (collisionsSecond->CheckCollisionRecs(rectangleFirst, rectangleSecond))
                    TriggerCollision(ref, firstEntityIndex, i);
            }
        }
    }

    void EntityCollision(Otter::Core::Orchestrator& ref)
    {
        auto& collisions = ref.get_components<components::BoxCollider>();
        auto& transforms = ref.get_components<components::Transform>();

        for (size_t i = 0; i < collisions.size() && i < transforms.size(); i++) {
            auto& collisionFirst = collisions[i];
            auto& transformFirst = transforms[i];
            if (!collisionFirst || !transformFirst)
                continue;
            SecondEntityCollision(ref, collisions, transforms, i);
        }
    }

} // namespace Otter::Games::RType::System::Collision