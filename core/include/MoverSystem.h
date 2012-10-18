#include "IEntitySystem.h"

class MoverSystem : public IEntitySystem {
    public:
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */);
};