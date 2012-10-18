#include <string>
#include <map>

#include "ComponentType.h"

class IComponent;

class Entity {
public:
	void SetId(std::string id);
	std::string GetId();

    bool HasComponent(ComponentType type);
    IComponent* GetComponent(ComponentType type);
    bool AddComponent(IComponent* component);
    bool RemoveComponent(ComponentType type);

private:
	std::string m_id;

    std::map<ComponentType, IComponent*> m_components;
};