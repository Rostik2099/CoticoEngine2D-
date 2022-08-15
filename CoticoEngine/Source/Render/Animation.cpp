#include "Animation.h"

Animation::Animation(sf::Sprite* sprite, sf::Vector2u imageCount, float switchTime, std::string pathToFile, bool isLooping)
{
	this->originalSprite = *sprite;
	this->targetSprite = sprite;
	this->animAtlas.loadFromFile(pathToFile);
	this->targetSprite->setTexture(animAtlas);
	this->targetSprite->setScale(sf::Vector2f(10.f, 10.f));
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->looping = isLooping;

	this->uvRect = sf::IntRect(0, 0, this->animAtlas.getSize().x / imageCount.x, this->animAtlas.getSize().y / imageCount.y);
}

Animation::~Animation(){}

void Animation::Tick(float dt)
{
	this->totalTime += dt;

	if (this->totalTime >= this->switchTime)
	{
		totalTime -= switchTime;
		this->currentImage.x++;

		if (this->currentImage.x >= imageCount.x)
		{
			currentImage.y++;
			currentImage.x = 0;
			if (currentImage.y >= imageCount.y)
			{
				if (this->looping)
				{
					currentImage.y = 0;
					currentImage.x = 0;
				}
				else Stop();
			}
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

	this->targetSprite->setTextureRect(this->uvRect);
}

void Animation::Stop()
{
	
}
