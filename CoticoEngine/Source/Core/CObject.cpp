#include "CObject.h"

CObject::CObject() {}

sf::Drawable& CObject::GetForDraw()
{
    return sf::RectangleShape();
}

void CObject::AddTick() {}

CObject::~CObject() {}
