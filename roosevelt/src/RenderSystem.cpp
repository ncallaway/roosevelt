#include "RenderSystem.h"

#include <stdio.h>

#include "EntityContainer.h"
#include "Entity.h"

#include "IRenderer.h"

#include "PositionComponent.h"
#include "RenderComponent.h"

RenderSystem::RenderSystem(IRenderer* renderer)
{
    mp_renderer = renderer;
}

void RenderSystem::Update(EntityContainer* container)
{

    mp_renderer->Clear();

    std::set<Entity*> entities = container->Query();

    std::set<Entity*>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++) {
        Entity* entity = (*it);

        if (!entity->HasComponent(PositionComponent::TYPE) || !entity->HasComponent(RenderComponent::TYPE)) {
            continue;
        }

        PositionComponent* position = dynamic_cast<PositionComponent*>(entity->GetComponent(PositionComponent::TYPE));
        RenderComponent* render = dynamic_cast<RenderComponent*>(entity->GetComponent(RenderComponent::TYPE));

        mp_renderer->DrawRectangle(position->X(), position->Y(), 20, 20, render->R(), render->G(), render->B());
    }

    mp_renderer->Present();
}