#include "Border.h"

Border::Border() {}

Border::~Border() {}

sf::Drawable& Border::GetForDraw()
{
	return this->border;
}

void Border::Tick(float dt) {}

void Border::SetProperties(std::list<std::pair<std::string, std::string>> properties)
{
	BorderParams params = GetBorderParams(properties);
	this->border.setPosition(params.position);
	this->border.setSize(params.size);
	this->border.setFillColor(params.color);
}
