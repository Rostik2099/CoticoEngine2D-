#include "Animation.h"
#include "Core/CEngine.h"

Animation::Animation (sf::Sprite* sprite, std::string pathToFile)
{
	this->originalSprite = *sprite;
	this->targetSprite = sprite;
	this->animAtlas.loadFromFile(pathToFile);
	this->targetSprite->setTexture(animAtlas);
	this->targetSprite->setScale(sf::Vector2f(10.f, 10.f));
	this->imageCount = sf::Vector2u(6, 1);
	this->switchTime = 0.10f;
	this->looping = false;

	this->uvRect = sf::IntRect(0, 0, this->animAtlas.getSize().x / this->imageCount.x, this->animAtlas.getSize().y / this->imageCount.y);
}

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
	if (!isPaused)
	{
		this->totalTime += dt;

		if (this->totalTime >= this->switchTime)
		{
			totalTime = 0.f;
			this->currentImage.x++;

			if (this->currentImage.x >= imageCount.x)
			{
				currentImage.y++;
				currentImage.x = 0;
				if (currentImage.y >= imageCount.y)
				{
					currentImage.y = 0;
					currentImage.x = 0;
					if(!this->looping)
						Stop();
				}
			}
		}

		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;

		this->targetSprite->setTextureRect(this->uvRect);
	}
}

void Animation::Stop()
{	
	this->isPaused = true;

	//Удалять анимации потом здесь
	//GetEngine()->DeleteAnimation(this);
	//delete this;
}
