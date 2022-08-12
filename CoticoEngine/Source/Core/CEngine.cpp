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
	ImGui::SFML::Shutdown();
	delete this->window;
}

void CEngine::Init()
{
	std::cout << "Welcome to Cotico Engine! The best engine in the world!!!" << std::endl;
}

void CEngine::CreateWindow(unsigned int windowWidth, unsigned int windowHeight, std::string windowName, sf::Uint32 windowStyle, unsigned int frameLimit)
{
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowName, windowStyle);
	if (frameLimit != 0) this->window->setFramerateLimit(frameLimit);
}

void CEngine::UpdateWindowEvents()
{
	this->windowEvent = new sf::Event;
	while (this->window->pollEvent(*this->windowEvent))
	{
		ImGui::SFML::ProcessEvent(*this->windowEvent);
		if (this->windowEvent->type == sf::Event::Closed)
			this->window->close();
	}
	delete this->windowEvent;
}

void CEngine::Update()
{
	ImGui::SFML::Update(*this->window, deltaClock.restart());

	ImGui::Begin("Ruslan kaban");
	ImGui::Text("Bebronuh");
	ImGui::End();
}

void CEngine::Draw()
{
	this->window->clear();

	for(auto &t : Objects) {
		this->window->draw(t->GetForDraw());
		t->AddTick();
	}

	ImGui::SFML::Render(*this->window);
	this->window->display();
}

void CEngine::CreateText(std::string text, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelay, float lineSpacing, sf::Color textColor, sf::Text::Style textStyle)
{
	TextBlock *newText = new TextBlock(text, position, size, pathToFont, fontSize, appearingDelay, lineSpacing, textColor, textStyle);

	this->Objects.push_back(newText);

	for(auto &t : newText->children) this->Objects.push_back(t);
}
