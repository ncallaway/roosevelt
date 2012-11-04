#ifndef SDL_RENDERER_ADAPTER
#define SDL_RENDERER_ADAPTER

#include <SDL.h>

#include "IRenderer.h"

/**
 A simple adapter that implements the IRenderer interface and uses SDL to draw some very primitive
 stuff.
*/
class SDLRendererAdapter : public IRenderer {
	public:
        /**
         \param renderer A pointer to an SDL_Renderer to use to render things.
        */
		SDLRendererAdapter(SDL_Renderer* renderer);

		void Clear();
		void DrawRectangle(double x, double y, double width, double height, int r, int g, int b);
		void Present();

	private:
		SDL_Renderer* mp_renderer;
};

#endif // SDL_RENDERER_ADAPTER