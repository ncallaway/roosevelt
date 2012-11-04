// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>

#include "EntityContainer.h"
#include "PositionComponent.h"
#include "MoverSystem.h"
#include "PrinterSystem.h"
#include "EntityContainer.h"
#include "RenderSystem.h"
#include "RenderComponent.h"
#include "Entity.h"
#include "SDLRendererAdapter.h"

int main (int argc, char* argv[])
{

    SDL_Window* p_window;
    SDL_Renderer* p_renderer;

    SDL_Event event;

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    p_window = SDL_CreateWindow("I am Fucking Awesome", 50, 50, 500, 500, SDL_WINDOW_SHOWN);
    p_renderer = SDL_CreateRenderer(p_window, -1, 0);



    EntityContainer* world = new EntityContainer();
    Entity* entity = new Entity();
    entity->SetId("XKCD");

    world->AddEntity(entity);

    PositionComponent* startingPosition = new PositionComponent();
    startingPosition->SetY(10);
    startingPosition->SetX(-10);

    RenderComponent* renderComponent = new RenderComponent();
    renderComponent->SetR(255);
    renderComponent->SetG(0);
    renderComponent->SetB(0);

    entity->AddComponent(startingPosition);
    entity->AddComponent(renderComponent);

    IRenderer* renderAdapter = new SDLRendererAdapter(p_renderer);

    EntitySystem* mover = new MoverSystem();
    EntitySystem* printer = new PrinterSystem();
    EntitySystem* renderer = new RenderSystem(renderAdapter);

    for (int i=0; i<100; i++) {


        if (i%2 == 0) {
            printer->Update(world);
        }
    }

    bool quit = false;
    int frame = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            quit |= event.type == SDL_QUIT;
        }

        mover->Update(world);
        renderer->Update(world);

        if (frame == 1000) {
            printer->Update(world);
            frame = 0;
        }

        frame++;
    }

    SDL_DestroyRenderer(p_renderer);
    SDL_DestroyWindow(p_window);

    // Quit SDL
    SDL_Quit();

    return 0;
}
