#include "EntityComponent.h"

ComponentType EntityComponent::RegisterComponent()
{
    ComponentType returnValue = s_registeredComponents;
    s_registeredComponents++;
    return returnValue;
}

ComponentType EntityComponent::s_registeredComponents = 0;