#include "CObject.h"

CObject::CObject()
{

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
