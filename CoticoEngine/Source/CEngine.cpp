#include "CEngine.h"

CEngine::CEngine()
{
	this->Init();
}

CEngine::~CEngine()
{
	std::cout << "Goodbye sweetie" << std::endl;
	std::cout << "GPU self-destruct programm initiated" << std::endl;
	sf::Clock clock;
	sf::Time time1 = clock.getElapsedTime();
	for(int i = 0; i < 100; i += 5) {
		std::cout << i << "% complete" << std::endl; 
		while(true) {
			time1 = clock.getElapsedTime();
			if (time1.asSeconds() > 0.6) {clock.restart(); break;}
		}
	}
	std::cout << "Thanks for using our software. With love, CANAVA *cmok*" << std::endl;
	//std::cout << "¯\_(ツ)_/¯" << std::endl;
	delete this->window;
}

void CEngine::Init()
{
	std::cout << "Welcome to Cotico Engine! The best engine in the world!!!" << std::endl;
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