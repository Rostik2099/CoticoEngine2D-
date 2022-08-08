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
};



class StaticObject : public CObject
{
	sf::Sprite sprite;
};



class SemiStaticcObject : public CObject
{
public:
	std::vector<sf::Sprite> states;

	int animationStage; // если анимация не началась то 0
	bool StartAnimation(sf::Clock dT, float probability); // если возвращает true, то выставляет animationStage на states.size() - 1
};