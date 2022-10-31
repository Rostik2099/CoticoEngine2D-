#pragma once

#include "UI/Widget.h"

class MainMenuWidget : public Widget
{
public:
	MainMenuWidget();

	virtual void OnConstruct() override;
	virtual void Tick(float dt) override;

private:
	class Button* newGame;
	class Button* exit;

public:
	class Level* curLvl;
};

