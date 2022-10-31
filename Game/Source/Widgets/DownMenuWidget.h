#pragma once
#include "UI/Widget.h"

class DownMenuWidget : public Widget
{
public:
	DownMenuWidget();

	void OnConstruct() override;
	void Tick(float dt) override;

	class Level* level;

	class TextBlock* leftText;
	class TextBlock* rightText;
	class TextBlock* mainText;

	std::string leftLevel;
	std::string rightLevel;
private:
	class Button* left;
	class Button* right;
};

