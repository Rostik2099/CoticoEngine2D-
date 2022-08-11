#include "CObject.h"

CObject::CObject() {}

sf::Drawable& CObject::GetForDraw()
{
    //sf::Shape* empty = new sf::Shape();
    return sf::RectangleShape();
}

void CObject::AddTick() {}

CObject::~CObject() {}
