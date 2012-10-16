#include "Entity.h"

void Entity::set_id(std::string id) {
	m_id = id;
}

std::string Entity::get_id() {
	return m_id;
}