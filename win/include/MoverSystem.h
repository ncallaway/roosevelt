#ifndef MOVER_SYSTEM
#define MOVER_SYSTEM

#include "IEntitySystem.h"

/**
 A dumb demo system that moves Entities that have a POSITION_COMPONENT somewhat arbitrarily.
*/
class MoverSystem : public IEntitySystem {
    public:
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */);
};

#endif // MOVER_SYSTEM