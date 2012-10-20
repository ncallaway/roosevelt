#ifndef I_ENTITY_SYSTEM
#define I_ENTITY_SYSTEM

class EntityContainer;

/**
 EntitySystem is the interface that EntitySystems must implement. These will be used to drive the
 main logic of the game.

 An EntitySystem processes on sets of Entities within an EntityContainer. The EntitySystem uses
 the Query mechanism provided by the EntityContainer to retrive Entities it is interested in
 dealing with. It then uses the data in the EntityComponents of the Entities to drive the game logic.

 For example, a PhysicsSystem might query for all Entities in an EntityContainer that have a
 PHYSICS_COMPONENT. The PhysicsSystem might then apply velocity and collisions to the various
 Entities, and update the data in the relative components.
*/
class EntitySystem {
    public:
        /**
         Virtaul destructor! Yay not memory leaks.
        */
        virtual ~EntitySystem() {}

        /**
         Update the Entities within the given EntityContainer

         \param container EntityContainer that contains the Entities to update.
        */
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */) = 0;
};

#endif // I_ENTITY_SYSTEM