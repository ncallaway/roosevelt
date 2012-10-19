#ifndef PRINTER_SYSTEM
#define PRINTER_SYSTEM

#include "IEntitySystem.h"

class PrinterSystem : public IEntitySystem {
    public:
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */);
};

#endif // PRINTER_SYSTEM