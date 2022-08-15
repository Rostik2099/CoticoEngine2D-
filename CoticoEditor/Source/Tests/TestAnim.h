#pragma once
#include "Core\CObject.h"

class TestAnim : public CObject
{
public:
	TestAnim();

	virtual sf::Drawable& GetForDraw() override;
public:
	sf::Sprite sprite;
	sf::Texture tex;
};

