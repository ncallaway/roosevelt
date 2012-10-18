#include "IEntitySystem.h"

class PrinterSystem : public IEntitySystem {
    public:
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */);
};