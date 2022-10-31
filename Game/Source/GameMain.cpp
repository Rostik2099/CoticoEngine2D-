#include <Windows.h>
#include "Core/CEngine.h"
#include "Level.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    ShowWindow(GetConsoleWindow(), SW_SHOW);
#ifdef SHIPPING
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
    CEngine Engine;
    Engine.CreateAppWindow(1280, 720, "Cotico Adventure", sf::Style::Default, 60);
    Engine.appType = Game;

    Level lvl;
    Engine.AddObject(&lvl);

    //Main Loop
    while (Engine.window->isOpen())
    {
        Engine.UpdateWindowEvents();
        Engine.Update();
        Engine.Draw();
    }

    return 0;
}