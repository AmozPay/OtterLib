/*
** EPITECH PROJECT, 2023
** R_type
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_
#include <cstdint>
#include <queue>
#include <stdexcept>
using Entity = std::uint32_t;
#define MAX_ENTITY 1000

namespace Core {

// add template<> or arg for scene  to store array of entity per scene

class EntityManager {
  public:
    EntityManager();
    ~EntityManager();
    Entity CreateEntity();
    void destroyEntity(Entity entity);

  protected:
  private:
    std::queue<Entity> _availableEntity;
    // queue set with all id possible, assure the good balance of the id
    std::size_t _livingEntityCount;
};
} // namespace Core
#endif /* !ENTITYMANAGER_HPP_ */
