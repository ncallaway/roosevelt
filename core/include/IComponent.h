#ifndef I_COMPONENT
#define I_COMPONENT

#include "ComponentType.h"

/**
 The IComponent represents a set of data that is attached to an Entity.
 
 Each subclass of IComponent should have a 1:1 correlation with a ComponentType (for example
 PositionComponent and POSITION_COMPONENT). This is a bad design, and should be revisted in the
 future.

 Each Entity may only have one component of a given type attached to it (that is, only one
 POSITION_COMPONENT may be attached to any given Entity).

 Finally, the presence of an IComponent of a specific type is semantically relevant to the Entity
 it is attached to. That is to say, the presence of a HealthComponent implies that the Entity has
 health related concerns; an Entity that has no HealthComponent does not have health in any sense.
*/
class IComponent {
	public:
        /**
         Virtaul destructor! Yay not memory leaks.
        */
        virtual ~IComponent() {}

        /**
         Get the ComponentType that this IComponent represents.

         \return The ComponentTypethat this IComponent represents.
        */
		virtual ComponentType GetType() = 0;
};

#endif // I_COMPONENT