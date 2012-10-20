#ifndef MOVER_SYSTEM
#define MOVER_SYSTEM

#include "EntitySystem.h"

/**
 A dumb demo system that moves Entities that have a POSITION_COMPONENT somewhat arbitrarily.
*/
class MoverSystem : public EntitySystem {
    public:
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */);
};

#endif // MOVER_SYSTEM