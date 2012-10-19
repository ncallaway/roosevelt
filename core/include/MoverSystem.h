#ifndef MOVER_SYSTEM
#define MOVER_SYSTEM

#include "IEntitySystem.h"

class MoverSystem : public IEntitySystem {
    public:
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */);
};

#endif // MOVER_SYSTEM