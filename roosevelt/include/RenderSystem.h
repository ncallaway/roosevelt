#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "RenderSystem.h"
#include "EntitySystem.h"

class IRenderer;

/**
 A dumb demo system that renders the position of Entities that have a PositionComponent and a
 RenderComponent.
*/
class RenderSystem : public EntitySystem {
    public:
		RenderSystem(IRenderer* renderer);
        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */);

	private:
		IRenderer* mp_renderer;
};

#endif // RENDER_SYSTEM