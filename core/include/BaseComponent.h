#include "IComponent.h"

class BaseComponent : public IComponent {
	protected:
		BaseComponent(ComponentType type);

	public:
		virtual ComponentType GetType();

	protected:
		ComponentType m_type;
};