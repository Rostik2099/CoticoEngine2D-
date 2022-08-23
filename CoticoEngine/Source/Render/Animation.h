#pragma once
#include "Core/CObject.h"

class Animation : public CObject
{
public:
	Animation(sf::Sprite* sprite, std::string pathToFile);
	Animation(sf::Sprite* sprite, sf::Vector2u imageCount, float switchTime, std::string pathToFile, bool isLooping);
	~Animation();

	virtual void Tick(float dt) override;

	void Stop();
	void Pause() { this->isPaused = true; }
	void Continue() { this->isPaused = false; };

private:
	sf::Texture animAtlas;
	sf::Sprite originalSprite;

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::IntRect uvRect;

	float totalTime = 0;
	float switchTime;

	bool looping;

	sf::Sprite* targetSprite;

	bool isPaused = false;
};

