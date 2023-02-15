/*
** EPITECH PROJECT, 2023
** otter_Lib
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

namespace Otter::Core {
    EntityManager::EntityManager()
    {
        for (Entity it = 1; it < MAX_ENTITY; it++)
            _availableEntity.insert(it);
    }

    EntityManager::~EntityManager() {}

    Entity EntityManager::CreateEntity()
    {

        if (_availableEntity.size() == 0) {
            throw std::runtime_error("too much entities");
        }
        auto enti = _availableEntity.extract(_availableEntity.begin());
        return (enti.value());
    }

    void EntityManager::destroyEntity(Entity entity)
    {
        if (entity < 0) {
            throw std::runtime_error("Entity not in range");
        }
        _availableEntity.insert(entity);
    }
} // namespace Otter::Core
