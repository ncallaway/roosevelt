#include "RenderComponent.h"

#include "EntityComponent.h"

RenderComponent::RenderComponent() : BaseComponent(TYPE),
    m_r(0),
    m_g(0),
	m_b(0)
{}

int RenderComponent::R() {
    return m_r;
}

int RenderComponent::G() {
    return m_g;
}

int RenderComponent::B() {
    return m_b;
}

void RenderComponent::SetR(int r) {
    m_r = ClampColor(r);
}

void RenderComponent::SetG(int g) {
    m_g = ClampColor(g);
}

void RenderComponent::SetB(int b) {
    m_b = ClampColor(b);
}

int RenderComponent::ClampColor(int value) {
	if (value < 0) return 0;
	if (value > 255) return 255;
	return value;
}

const ComponentType RenderComponent::TYPE = EntityComponent::RegisterComponent();