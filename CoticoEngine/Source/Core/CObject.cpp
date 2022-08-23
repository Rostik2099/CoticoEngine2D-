#include "CObject.h"
#include "Core/CEngine.h"

CObject::CObject() {}
CObject::~CObject() {}

sf::Vector2f CObject::GetMousePosition()
{
    sf::Mouse mouse;
    
    return sf::Vector2f(mouse.getPosition(*engine->window).x, mouse.getPosition(*engine->window).y);
}

sf::Drawable& CObject::GetForDraw()
{
    return sf::RectangleShape();
}

void CObject::Tick(float dt) {}

void CObject::BeginPlay() {}

void CObject::setTransparency(float procent) {}

CEngine* CObject::GetEngine()
{
    return this->engine;
}

void CObject::SetEngine(CEngine* engine)
{
    this->engine = engine;
}

Animation* CObject::PlayAnimation(sf::Sprite* sprite, std::string pathToFile)
{
    Animation* newAnim = new Animation(sprite, pathToFile);
    GetEngine()->CreateAnimation(newAnim, pathToFile);
    return newAnim;
};