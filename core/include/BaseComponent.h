#ifndef BASE_COMPONENT
#define BASE_COMPONENT

#include "EntityComponent.h"

/**
 A basic implementation of EntityComponent that takes a type in the constructor and returns that type
 in the GetType function.
*/
class BaseComponent : public EntityComponent {
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