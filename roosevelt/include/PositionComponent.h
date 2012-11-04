#ifndef POSITION_COMPONENT
#define POSITION_COMPONENT

#include "BaseComponent.h"

/**
 A dumb component that holds simple x and y coordinates.
*/
class PositionComponent : public BaseComponent
{
    public:
        PositionComponent();

        /**
         Get the 'x' position of the Entity.
         \return The 'x' position of the Entity.
        */
        double X();

        /**
         Get the 'y' position of the Entity.
         \return The 'y' position of the Entity.
        */
        double Y();

        /**
         Set the 'x' position of the Entity.
         \param x The 'x' position of the Entity to set.
        */
        void SetX(double x);

        /**
         Set the 'y' position of the Entity.
         \param y The 'y' position of the Entity to set.
        */
        void SetY(double y);

        static const ComponentType TYPE;

    private:
        double m_x;
        double m_y;
};

#endif // POSITION_COMPONENT