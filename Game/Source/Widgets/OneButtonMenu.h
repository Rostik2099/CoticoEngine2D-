#pragma once
#include "UI\Widget.h"
class OneButtonMenu : public Widget
{
public:
	OneButtonMenu();

	virtual void OnConstruct() override;
	virtual void Tick(float dt) override;

public:
	class Level* level;

	class Button* leftButton;
	class TextBlock* leftText;
	class TextBlock* mainText;

	std::string leftLevel;
};

