#pragma once
#include"UI/Widget.h"

class TWidget : public Widget
{
public:
	TWidget();

	class Button* button;
	class Button* button2;
	class Animation* anim;

	virtual void Tick(float dt) override;
	virtual void OnConstruct() override;
};

