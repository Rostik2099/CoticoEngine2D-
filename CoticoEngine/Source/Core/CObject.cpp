#include "CObject.h"

CObject::CObject()
{
    sf::Sprite biba;
    boba.push_back(biba);
}

void CObject::SetEngine(CEngine* engine)
{
    this->engine = engine;
}

CEngine* CObject::GetEngine()
{
    return this->engine;
}

void CObject::SendToRender()
{
    
}

CObject::~CObject()
{
}
