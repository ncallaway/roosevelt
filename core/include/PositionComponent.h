#ifndef POSITION_COMPONENT
#define POSITION_COMPONENT

#include "BaseComponent.h"

class PositionComponent : public BaseComponent {
    public:
        PositionComponent();

        double X();
        double Y();

        void SetX(double x);
        void SetY(double y);

    private:
        double m_x;
        double m_y;
};

#endif // POSITION_COMPONENT