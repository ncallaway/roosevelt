#ifndef PRINTER_SYSTEM
#define PRINTER_SYSTEM

#include "EntitySystem.h"

/**
 A dumb demo system that prints the position of Entities that have a POSITION_COMPONENT.
*/
class PrinterSystem : public EntitySystem {
    public:
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */);
};

#endif // PRINTER_SYSTEM