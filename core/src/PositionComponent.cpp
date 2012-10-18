#include "PositionComponent.h"

PositionComponent::PositionComponent() :
    BaseComponent(POSITION_COMPONENT),
    m_x(0),
    m_y(0)
{}

double PositionComponent::X() {
    return m_x;
}

double PositionComponent::Y() {
    return m_y;
}

void PositionComponent::SetX(double x) {
    m_x = x;
}

void PositionComponent::SetY(double y) {
    m_y = y;
}