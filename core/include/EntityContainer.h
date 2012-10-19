#ifndef ENTITY_CONTAINER
#define ENTITY_CONTAINER

#include <set>

class Entity;

/**
 EntityContainer represents a place where Entities co-exist. This can be an entire world, one
 scene, one level, or any other place where Entities interact. Generally two Entities that are
 contained in separate containers will not interact with each other.

 The EntityContainer holds Entities within it. Through the Query() function (later to become an
 interface), the Entity makes specific Entities available to an EntitySystem. These EntitySystems
 will process the various Entities within the container and drive the main logic of the game.
*/
class EntityContainer {
    public:
        /**
         Add an Entity to this EntityContainer. Each Entity may only be added to the container
         once, so attempting to add the same Entity a second time will cause AddEntity() to return
         false.

         \param entity The Entity to add to this EntityContainer. NULL Entities will not be added.
         \return True if the entity was added to the container. False if the Entity could not be
         added to the container (usually because the Entity is already present within the
         contanier). Will always return false on NULL input.
        */
        bool AddEntity(Entity* entity);

        /**
         Remove an Entity from this EntityContainer. This will return whether the Entity was
         successfully removed.

         \param entity The Entity to remove from this EntityContainer.
         \return True if the Entity was removed from the container. False if the Entity was not
         present within the container.
        */
        bool RemoveEntity(Entity* entity);

        /**
         Determine if this EntityContainer contains the given Entity.

         \param entity The Entity to find within this EntityContainer.
         \return True if the Entity exists within the EntityContainer. False otherwise.
        */
        bool HasEntity(Entity* entity);

        /**
         Currently this returns all Entities within this EntityContainer.

         \return All Entities within this EntityContainer.
        */
        std::set<Entity*> Query();

    private:
        std::set<Entity*> m_entities;
};

#endif // ENTITY_CONTAINER