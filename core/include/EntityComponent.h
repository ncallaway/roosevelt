#ifndef ENTITY_COMPONENT
#define ENTITY_COMPONENT

#include "ComponentType.h"

/**
 The EntityComponent represents a set of data that is attached to an Entity.
 
 Each subclass of EntityComponent should have one static ComponentType that represents the type
 for that class. The common pattern is to have a single public static const class member that
 calls RegisterComponent() as its static initializer. This isn't a great design, and may be
 revisted in the future.

 Each Entity may only have one component of a given type attached to it (that is, only one
 PositionComponent may be attached to any given Entity).

 Finally, the presence of an EntityComponent of a specific type is semantically relevant to the Entity
 it is attached to. That is to say, the presence of a HealthComponent implies that the Entity has
 health related concerns; an Entity that has no HealthComponent does not have health in any sense.
*/
class EntityComponent {
	public:
        /**
         Virtaul destructor! Hurray for not having memory leaks.
        */
        virtual ~EntityComponent() {}

        /**
         Get the ComponentType that this EntityComponent represents.

         \return The ComponentTypethat this EntityComponent represents.
        */
		virtual ComponentType GetType() = 0;

    protected:
        /**
         Register a new type of component and get back the ComponentType that will represent that
         component.

         \return The ComponentType that will represent the registered component.
        */
        static ComponentType RegisterComponent();

    private:
        static ComponentType s_registeredComponents;
};

#endif // ENTITY_COMPONENT