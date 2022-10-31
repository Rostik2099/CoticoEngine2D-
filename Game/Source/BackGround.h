#pragma once

#include "Core/CObject.h"

class BackGround : public CObject
{
private:
	sf::Sprite bgSprite;
	sf::Texture bgTexture;
public:
	BackGround()
	{
		this->bgTexture.loadFromFile("Content/Images/1.jpg");
		this->bgSprite.setTexture(bgTexture, true);

		ResizeBG();
	};

	void ChangeBG(std::string imageName)
	{
		std::string path = "Content/Images/";
		path += imageName;
		this->bgTexture.loadFromFile(path);
		this->bgSprite.setTexture(bgTexture, true);
		ResizeBG();
	};

private:
	sf::Drawable& GetForDraw() override
	{
		return this->bgSprite;
	};

	void ResizeBG()
	{
		bgSprite.setScale(sf::Vector2f(1.f, 1.f));
		float arX = bgSprite.getLocalBounds().width / 1280;
		float arY = bgSprite.getLocalBounds().height / 720;
		bgSprite.setScale(sf::Vector2f(bgSprite.getScale().x / arX, bgSprite.getScale().y / arY));
	};
};