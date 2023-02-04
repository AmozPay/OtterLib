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
        _livingEntityCount = 0;
        for (Entity it = 1; it < MAX_ENTITY; it++)
            _availableEntity.insert(it);
    }

    EntityManager::~EntityManager() {}

    Entity EntityManager::CreateEntity()
    {
        Entity enti;

        if (_availableEntity.max_size() >= MAX_ENTITY) {
            throw std::runtime_error("too much entities");
        }
        enti = _availableEntity.extract(_availableEntity.begin());
        return (enti);
    }

    void EntityManager::destroyEntity(Entity entity)
    {
        if (entity < 0) {
            throw std::runtime_error("Entity not in range");
        }
        _availableEntity.insert(entity);
    }
} // namespace Otter::Core
