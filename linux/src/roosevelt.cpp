#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "EntityContainer.h"
#include "PositionComponent.h"
#include "MoverSystem.h"
#include "PrinterSystem.h"
#include "EntityContainer.h"
#include "RenderSystem.h"
#include "RenderComponent.h"
#include "Entity.h"

// #include <SFML/Graphics.hpp>

int main (int argc, char* argv[])
{
    // SDL SAMPLE
    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    // return 0;
    // !SAMPLE

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

    EntitySystem* mover = new MoverSystem();
    EntitySystem* printer = new PrinterSystem();

    for (int i=0; i<100; i++) {
        if (i%2 == 0) {
            printer->Update(world);
        }
    }

    return 0;
}
