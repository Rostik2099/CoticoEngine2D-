#include <Windows.h>
#include "Core/CEngine.h"

int main() 
{
    ShowWindow(GetConsoleWindow(), SW_SHOW);
#ifdef SHIPPING
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
    CEngine Engine;
    Engine.CreateAppWindow(1280, 720, "Cool game", sf::Style::Default);
    Engine.appType = Game;

    sf::CircleShape circle(100.f);
    circle.setPosition(float(Engine.window->getSize().x) / 2, float(Engine.window->getSize().y) / 2);
    circle.setFillColor(sf::Color::Green);

    //Main Loop
    while (Engine.window->isOpen())
    {
        Engine.UpdateWindowEvents();
        Engine.Update();
        Engine.Draw();
    }

    return 0;
}