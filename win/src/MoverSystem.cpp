#include "MoverSystem.h"

#include "EntityContainer.h"
#include "Entity.h"

#include "PositionComponent.h"

void MoverSystem::Update(EntityContainer* container) {
    std::set<Entity*> entities = container->Query();

    std::set<Entity*>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++) {
        if (!(*it)->HasComponent(PositionComponent::TYPE)) {
            continue;
        }

        PositionComponent* position = dynamic_cast<PositionComponent*>((*it)->GetComponent(PositionComponent::TYPE));

        if (position->X() < 20) {
            position->SetX(position->X() + .5);
        } else {
            position->SetX(0);
        }

        if (position->Y() > 0.01) {
            position->SetY(position->Y() * 0.5);
        } else {
            position->SetY(0);
        }
    }
}