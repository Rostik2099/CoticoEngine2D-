#pragma once

#include "UI/UIObject.h"

class Border : public UIObject
{
public:
	Border();
	~Border();

	virtual sf::Drawable& GetForDraw() override;
	virtual void Tick(float dt) override;
	virtual void SetProperties(std::list<std::pair<std::string, std::string>> properties) override;

private:
	sf::RectangleShape border;

};

