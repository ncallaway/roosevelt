#include "Entity.h"

#include "EntityComponent.h"

void Entity::SetId(std::string id) {
	m_id = id;
}

std::string Entity::GetId() {
	return m_id;
}

bool Entity::AddComponent(EntityComponent* component) {
    if (component == NULL) {
        return false;
    }

    ComponentType type = component->GetType();

    if (component == GetComponent(type)) {
        return true;
    }

    if (HasComponent(type)) {
        return false;
    }

    m_components[type] = component;
    return true;
}

bool Entity::RemoveComponent(ComponentType type) {
    if (HasComponent(type)) {
        m_components.erase(type);
        return true;
    }

    return false;
}

EntityComponent* Entity::GetComponent(ComponentType type) {
    if (HasComponent(type)) {
        return m_components[type];
    }

    return NULL;
}

bool Entity::HasComponent(ComponentType type) {
    return (m_components.count(type) > 0);
}