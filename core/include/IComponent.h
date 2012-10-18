#include "ComponentType.h"

class IComponent {
	public:
        virtual ~IComponent() {}

		virtual ComponentType GetType() = 0;
};