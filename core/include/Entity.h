#ifndef ENTITY
#define ENTITY

#include <string>
#include <map>

#include "ComponentType.h"

class EntityComponent;

/**
  The class that represents any "thing" in the game world.
  
  This can range from physical things (e.g. walls, characters) to pickups (powerups, items) to
  zones (player spawn, player win region, monster spawns). Anything that the game logic needs to
  interact with should be represented by an Entity.

  Entities are contained in an EntityContainer which provides a means of querying for Entities with
  certain properties.

  Entities are a bag of Components (which are themselves a bag of properties). The presence of a
  component is often semantically relevant (i.e. if a HealthComponent is available on an Entity,
  that implies the Entity has health of some sort; an Entity that does not contain an
  InventoryComponent cannot hold inventory items).

  Entities are processed in the update step by an EntitySystem. These do all the work of updating and
  rendering the Entities. For example, a CommandProcessorSystem might handle the Commands given to
  an Entity; next a PhysicsSystem runs which updates the physics for all physical Entities; finally
  a RenderSystem runs which draws the given Entities.
*/
class Entity {
public:
    /**
     Get the identifer associated with the Entity. As with SetId() this may move into a separate
     IdComponent.

     \return The identifer associated with the Entity.
    */
    std::string GetId();

    /**
     Set the identifier for the Entity. Note that this may move into an IdComponent.

     \param id The identifier to assign to this Entity. While the identifier should be unique
     within the EntityContainer the Entity does not validate this.
    */
    void SetId(std::string id);

    /**
     Determine whether this Entity has an EntityComponent of the given ComponentType. Each Entity may only
     have one component of any type, thus if this returns true you may not add a Component with the
     same type.

     \param type The ComponentType that this Entity will determine if it contains.
     \return True if the Entity contains a Component with ComponentType matching the 'type'
     parameter. If this returns true, you cannot add another component of the same type.
    */
    bool HasComponent(ComponentType type);

    /**
     Get the EntityComponent that this Entity contains that matches the given ComponentType. If this
     Entity does not contain an EntityComponent that has a type matching the 'type' parameter,
     GetComponent() will return NULL.

     \param type The ComponentType of the EntityComponent to retrieve from this Entity.
     \return The EntityComponent that this Entity contains that matches the 'type' parameter. Each
     Entity may only contain a single EntityComponent for a given type, so this will be the only
     EntityComponent that matches this type. If the Entity does not contain an EntityComponent that matches
     the given ComponentType GetComponent() will return NULL.
    */
    EntityComponent* GetComponent(ComponentType type);

	/**
	 Add an EntityComponent to this Entity. If the Entity already has an EntityComponent of the given
	 ComponentType the new component will not be added.

	 \param component EntityComponent to add to this Entity. If the Entity already has an EntityComponent of
	 the given ComponentType, component will not be added to the Entity. If this is NULL then
	 AddComponent() will return NULL.
	 \return True if the EntityComponent was added to the Entity. False if the Entity already contains
	 a Component with the same type, or if the given EntityComponent is NULL.
	*/
    bool AddComponent(EntityComponent* component);

	/**
	 Remove a Component from this Entity. If the Entity does not have an EntityComponent of the given
	 type, this will return false.

	 \param type The ComponentType of the EntityComponent to remove.
	 \return True if the Entity contains an EntityComponent of the given type, and it was removed.
	 False, otherwise.
	*/
    bool RemoveComponent(ComponentType type);

private:
    std::string m_id;

    std::map<ComponentType, EntityComponent*> m_components;
};

#endif // ENTITY