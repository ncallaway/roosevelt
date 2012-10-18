#include "BaseComponent.h"

BaseComponent::BaseComponent(ComponentType type) {
	m_type = type;
}

ComponentType BaseComponent::GetType() {
	return m_type;
}