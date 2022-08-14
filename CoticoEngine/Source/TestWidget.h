#pragma once
#include"UI/Widget.h"

class TestWidget : public Widget
{
public:
	TestWidget();

	class Button* button;
	class Button* button2;

	virtual void Tick() override;
	virtual void OnConstruct() override;
};

