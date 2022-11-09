#pragma once

#include "UI\Widget.h"

class HiddenWidget : public Widget
{
public:
	HiddenWidget() { this->pathToFile = "Content/Widgets/HiddenWidget.cewidget"; };

	void OnConstruct() override;
	void Tick(float dt) override;

public:
	class Level* level;
private:
	class Button* button;
};

