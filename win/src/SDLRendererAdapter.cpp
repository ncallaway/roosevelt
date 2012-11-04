#include "SDLRendererAdapter.h"

SDLRendererAdapter::SDLRendererAdapter(SDL_Renderer* renderer)
{
    mp_renderer = renderer;
}

void SDLRendererAdapter::Clear()
{
    SDL_SetRenderDrawColor(mp_renderer, 255, 255, 255, 255);
    SDL_RenderClear(mp_renderer);
}

void SDLRendererAdapter::DrawRectangle(double x, double y, double width, double height, int r, int g, int b)
{
    SDL_Rect rect = {(int)x+250, (int)y+250, (int)width, (int)height};
    SDL_SetRenderDrawColor(mp_renderer, r, g, b, 255);
    SDL_RenderDrawRect(mp_renderer, &rect);
}

void SDLRendererAdapter::Present()
{
    SDL_RenderPresent(mp_renderer);
}