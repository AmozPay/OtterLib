/*
** EPITECH PROJECT, 2023
** otter_Lib
** File description:
** EntityManager
*/

#include "EntityManager.hpp"
namespace Otter::Core {
EntityManager::EntityManager() {
    _livingEntityCount = 0;
    for (Entity it = 1; it < MAX_ENTITY; it++)
        _availableEntity.push(it);
}

EntityManager::~EntityManager() {}

Entity EntityManager::CreateEntity() {
    Entity enti;

    if (_livingEntityCount >= MAX_ENTITY) {
        throw std::runtime_error("too much entities");
    }
    enti = _availableEntity.front();
    _availableEntity.pop();
    _livingEntityCount += 1;
    return (enti);
}

void EntityManager::destroyEntity(Entity entity) {
    if (entity < 0) {
        throw std::runtime_error("Entity not in range");
    }
    _availableEntity.push(entity);
    _livingEntityCount -= 1;
}
} // namespace Core
