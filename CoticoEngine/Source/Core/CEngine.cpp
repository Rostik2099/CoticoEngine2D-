#include "CEngine.h"
#include "TestWidget.h"

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
	if(this->appType == Editor)
		ImGui::SFML::Shutdown();
	delete this->windowEvent;
	delete this->window;
}

void CEngine::AddIGLayer(ImGuiLayer* newLayer)
{
	if (this->appType == Editor)
	{
		this->ImGuiLayers.push_back(newLayer);
	}
}

void CEngine::Init()
{
	std::cout << "Welcome to Cotico Engine! The best engine in the world!!!" << std::endl;
}

void CEngine::CreateAppWindow(unsigned int windowWidth, unsigned int windowHeight, std::string windowName, sf::Uint32 windowStyle, unsigned int frameLimit)
{
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowName, windowStyle);
	if (frameLimit != 0) this->window->setFramerateLimit(frameLimit);
}

void CEngine::UpdateWindowEvents()
{
	this->windowEvent = new sf::Event;
	while (this->window->pollEvent(*this->windowEvent))
	{
		if(this->appType == Editor)
			ImGui::SFML::ProcessEvent(*this->windowEvent);
		if (this->windowEvent->type == sf::Event::Closed)
			this->window->close();
	}
	delete this->windowEvent;
}

std::list<CObject*>::iterator CEngine::GetObjectsBegin() {return Objects.begin();}

void CEngine::Update()
{
	if (this->appType == Editor)
	{
		ImGui::SFML::Update(*this->window, this->deltaClock.restart());

		for (auto& layer : this->ImGuiLayers)
		{
			layer->Render();
			layer->Tick();
		}
	}
}

void CEngine::Draw()
{
	this->window->clear();

	for(auto &t : this->Objects) {
		this->window->draw(t->GetForDraw());
		t->Tick();
	}
	for (auto& widget : this->widgets)
	{
		widget->Draw();
		widget->Tick();
	}
	//std::cout << "Objects in window: " << Objects.size() << std::endl;
	if(this->appType == Editor)
		ImGui::SFML::Render(*this->window);
	this->window->display();
}

void CEngine::CreateText(std::list<CObject*>::iterator parentObject, std::string text, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelay, float lineSpacing, sf::Color textColor, sf::Text::Style textStyle)
{
	TextBlock *newText = new TextBlock(this->Objects, parentObject, text, position, size, pathToFont, fontSize, appearingDelay, lineSpacing, textColor, textStyle);
	newText->SetEngine(this);
}

Button* CEngine::CreateButton(sf::Vector2f position, sf::Vector2f size, sf::Color buttonIdleColor, sf::Color buttonHoverColor, sf::Color buttonPressedColor)
{
	Button* newButton = new Button(position, size, buttonIdleColor, buttonHoverColor, buttonPressedColor);
	newButton->SetEngine(this);

	this->Objects.push_back(newButton);
	
	return newButton;
}

void CEngine::CreateWidget(Widget* widgetToCreate)
{
	widgetToCreate->SetEngine(this);
	widgetToCreate->ReadFromFile();
	widgetToCreate->OnConstruct();

	this->widgets.push_back(widgetToCreate);
}
