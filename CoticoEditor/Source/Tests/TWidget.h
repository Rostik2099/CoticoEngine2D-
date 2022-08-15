#pragma once
#include"UI/Widget.h"

class TWidget : public Widget
{
public:
	TWidget();

	virtual void Tick(float dt) override;
};

