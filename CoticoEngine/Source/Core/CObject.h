#pragma once

#include "Core/CEngine.h"

class CObject
{

	//Functions
public:
	CObject();
	~CObject();

	void SetEngine(CEngine* engine);
protected:
	CEngine* GetEngine();

	virtual void SendToRender();
	//Variables
private:
	CEngine* engine;

	std::vector<sf::Sprite> boba;
};

