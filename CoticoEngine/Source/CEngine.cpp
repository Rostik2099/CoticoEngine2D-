#include "CEngine.h"

CEngine::CEngine()
{
	this->Init();
}

CEngine::~CEngine()
{
	delete this->window;
}

void CEngine::Init()
{
	std::cout << "Welcome to Cotico Engine!" << std::endl;
}

void CEngine::CreateWindow(unsigned int windowWidth, unsigned int windowHeight, std::string windowName, sf::Uint32 windowStyle)
{
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowName, windowStyle);
}

void CEngine::UpdateWindowEvents()
{
	this->windowEvent = new sf::Event;
	while (this->window->pollEvent(*this->windowEvent))
	{
		if (this->windowEvent->type == sf::Event::Closed)
			this->window->close();
	}
	delete this->windowEvent;
}

void CEngine::Update()
{
}

void CEngine::Draw(sf::CircleShape circle)
{
	this->window->clear();
	this->window->draw(circle);
	this->window->display();
}
