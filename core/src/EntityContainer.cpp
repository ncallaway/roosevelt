#include "EntityContainer.h"

#include "Entity.h"

bool EntityContainer::AddEntity(Entity* entity)
{
    if (entity == NULL) {
        return false;
    }

    if (HasEntity(entity)) {
        return false;
    }

    m_entities.insert(entity);
    return true;
}

bool EntityContainer::RemoveEntity(Entity* entity)
{
    if (entity == NULL) {
        return false;
    }

    if (HasEntity(entity)) {
        m_entities.erase(entity);
        return true;
    }

    return false;
}

bool EntityContainer::HasEntity(Entity* entity)
{
    if (entity == NULL) {
        return false;
    }
    return (m_entities.count(entity) > 0);
}

std::set<Entity*> EntityContainer::Query()
{
    std::set<Entity*> queryResults (m_entities);
    return queryResults;
}