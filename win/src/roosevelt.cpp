// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "EntityContainer.h"
#include "PositionComponent.h"
#include "MoverSystem.h"
#include "PrinterSystem.h"
#include "EntityContainer.h"
#include "Entity.h"

int main (int argc, char *argv[]) {
    EntityContainer* world = new EntityContainer();
    Entity* entity = new Entity();
    entity->SetId("XKCD");

    world->AddEntity(entity);

    PositionComponent* startingPosition = new PositionComponent();
    startingPosition->SetY(10);
    startingPosition->SetX(-10);

    entity->AddComponent(startingPosition);

    EntitySystem* mover = new MoverSystem();
    EntitySystem* printer = new PrinterSystem();

    for (int i=0; i<100; i++) {
        mover->Update(world);
        if (i%2 == 0) {
            printer->Update(world);
        }
    }

    return 0;
}
