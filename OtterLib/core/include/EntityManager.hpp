/*
** EPITECH PROJECT, 2023
** R_type
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_
#include <queue>

#define MAX_ENTITY 1000
using Entity = std::uint32_t;

// add template<> or arg for scene  to store array of entity per scene

class EntityManager {
  public:
    EntityManager();
    ~EntityManager();
    Entity CreateEntity();
    void destroyEntity(Entity entity);

  protected:
  private:
    std::queue<Entity>
        _availableEntity; // queue set with all id possible, assure the good balance of the id
    std::size_t _livingEntityCount;
};

#endif /* !ENTITYMANAGER_HPP_ */
