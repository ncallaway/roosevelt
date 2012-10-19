#ifndef BASE_COMPONENT
#define BASE_COMPONENT

#include "IComponent.h"

/**
 A basic implementation of IComponent that takes a type in the constructor and returns that type
 in the GetType function.
*/
class BaseComponent : public IComponent {
	protected:
		/**
		 \param type The ComponentType to return in the GetType() function call.
		*/
		BaseComponent(ComponentType type);

	public:
		virtual ComponentType GetType();

	protected:
		ComponentType m_type;
};

#endif // BASE_COMPONENT