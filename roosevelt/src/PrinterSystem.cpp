#include "PrinterSystem.h"

#include <stdio.h>

#include "EntityContainer.h"
#include "Entity.h"

#include "PositionComponent.h"

void PrinterSystem::Update(EntityContainer* container)
{
    std::set<Entity*> entities = container->Query();

    std::set<Entity*>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++) {
        Entity* entity = (*it);

        if (!entity->HasComponent(PositionComponent::TYPE)) {
            continue;
        }

        PositionComponent* position = dynamic_cast<PositionComponent*>(entity->GetComponent(PositionComponent::TYPE));

        fprintf(stdout, "Entity %s at: %f, %f\n", entity->GetId().c_str(), position->X(), position->Y());
    }
}