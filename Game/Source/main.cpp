#include "CEngine.h"

int main()
{
    CEngine Engine;
    Engine.CreateWindow(1280, 720, "Cotico Engine", sf::Style::Default);


    sf::CircleShape circle(100.f);
    circle.setPosition(Engine.window->getSize().x / 2, Engine.window->getSize().y / 2);
    circle.setFillColor(sf::Color::Green);

    //Main Loop
    while (Engine.window->isOpen())
    {
        Engine.UpdateWindowEvents();
        Engine.Update();
        Engine.Draw(circle);
    }

    return 0;
}