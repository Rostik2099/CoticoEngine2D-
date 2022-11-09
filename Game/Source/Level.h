#pragma once

#include "Core/CObject.h"
#include "BackGround.h"
#include "UI/Widget.h"

class Level : public CObject
{
public:
	Level() {};

	virtual void BeginPlay() override;

	sf::Drawable& GetForDraw() override
	{
		return sh;
	};

	void OpenLevel(std::string lvlName);

private:
	void ReadLevel(std::string levelName, std::list<std::pair<std::string, std::string>>& params);

private:
	sf::RectangleShape sh;
	BackGround* BG;
	Widget* currentWidget;
	Widget* hiddenWidget;

	std::string currentLvlType;
	std::string currentLvlName;
};

