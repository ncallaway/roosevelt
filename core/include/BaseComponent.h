#ifndef BASE_COMPONENT
#define BASE_COMPONENT

#include "IComponent.h"

class BaseComponent : public IComponent {
	protected:
		BaseComponent(ComponentType type);

	public:
		virtual ComponentType GetType();

	protected:
		ComponentType m_type;
};

#endif // BASE_COMPONENT