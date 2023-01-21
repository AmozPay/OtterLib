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

namespace Otter::Core {
using Entity = std::uint32_t;
#define MAX_ENTITY 1000

// add template<> or arg for scene  to store array of entity per scene


    /**
     * @class EntityManager
     * @brief manage all the entity, alocate id for new and free old id
     */
  class EntityManager {
  public:
    /**
     * @brief defualt constructor
     */
    EntityManager();
    ~EntityManager();

    /**
      * @brief register a new entity
     * @return entity newly create
     */
    Entity CreateEntity();

        /**
     * @brief destroy a entity
     * @details free id to let new object get id lower
     * @param entity to delete
     */
void destroyEntity(Entity entity);

  protected:
  private:
    std::queue<Entity> _availableEntity;
    // queue set with all id possible, assure the good balance of the id
    std::size_t _livingEntityCount;
};
} // namespace Core
#endif /* !ENTITYMANAGER_HPP_ */
