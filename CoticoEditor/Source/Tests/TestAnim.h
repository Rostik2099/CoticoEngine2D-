#pragma once
#include "Core\CObject.h"

class Widget;
class Animation;
class TestAnim : public CObject
{
public:
	TestAnim();

	virtual sf::Drawable& GetForDraw() override;
	virtual void BeginPlay() override;
public:
	sf::Sprite sprite;
	sf::Texture tex;
	Widget* widget;
	Animation* animation;
};

