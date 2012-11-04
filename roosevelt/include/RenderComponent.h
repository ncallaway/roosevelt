#ifndef RENDER_COMPONENT
#define RENDER_COMPONENT

#include "BaseComponent.h"

/**
 A dumb component that holds color information
*/
class RenderComponent : public BaseComponent {
	public:
        RenderComponent();

		/**
		 Get the 'r' component of the render color [0-255] for the Entity.
		 \return The 'r' component of the render color [0-255] for the Entity.
		*/
        int R();

		/**
		 Get the 'g' component of the render color [0-255] for the Entity.
		 \return The 'g' component of the render color [0-255] for the Entity.
		*/
        int G();

		/**
		 Get the 'b' component of the render color [0-255] for the Entity.
		 \return The 'b' component of the render color [0-255] for the Entity.
		*/
        int B();

		/**
		 Set the 'r' component of the render color [0-255]
		 \param r The 'r' component of the render color [0-255] for the Entity.
		*/
        void SetR(int r);

		/**
		 Set the 'g' component of the render color [0-255]
		 \param g The 'g' component of the render color [0-255] for the Entity.
		*/
        void SetG(int g);

		/**
		 Set the 'b' component of the render color [0-255]
		 \param b The 'b' component of the render color [0-255] for the Entity.
		*/
        void SetB(int b);

        static const ComponentType TYPE;

    private:
		int ClampColor(int value);

        int m_r;
        int m_g;
		int m_b;
};

#endif // RENDER_COMPONENT