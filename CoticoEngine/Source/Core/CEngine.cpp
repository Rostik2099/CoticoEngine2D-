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
	if(this->appType == Editor)
		ImGui::SFML::Shutdown();
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
	std::list<CObject*>::iterator &Object = GetObjectsBegin();
	TextBlock *newText = new TextBlock(Objects, Object, "Cotico Engine", sf::Vector2f(0.5, 0.5), sf::Vector2f(0.2, 0.2), "Content/Fonts/Calibri.ttf", 120, 0.0, 15.0, sf::Color::White, sf::Text::Bold);
	sf::Clock clock; 
	for(int i = 1; i > 0; i -= 0.01) {
		clock.restart();
		newText->setTransparency(i);
		while(clock.getElapsedTime().asSeconds() < 0.03);
	}
	DeteleObject(Object);
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

void CEngine::DeteleObject(std::list<CObject*>::iterator object) {
	if((object == Objects.begin()) || (object == Objects.end())) return;
	//&object.~CObject();
	object = Objects.erase(object);
}

void CEngine::AddObject(CObject* object)
{
	object->SetEngine(this);
	object->BeginPlay();
	this->Objects.push_back(object);
}

void CEngine::Update()
{
	this->deltaTime = this->deltaClock.getElapsedTime().asSeconds();

	if (this->appType == Editor)
	{
		ImGui::SFML::Update(*this->window, this->deltaClock.restart());

		for (auto& layer : this->ImGuiLayers)
		{
			layer->Render();
			layer->Tick();
		}
	}

	for (auto& anim : this->animations)
	{
		anim->Tick(deltaTime);
	}

	//Äכÿ חאלונא פןסא ט פנוילעאילא
	//std::cout << deltaTime << "  FPS: " << (float)1000/(deltaTime*(float)1000) << std::endl;
}

void CEngine::Draw()
{
	this->window->clear();

	for(auto &t : this->Objects) {
		this->window->draw(t->GetForDraw());
		t->Tick(this->deltaTime);
	}
	for (auto& widget : this->widgets)
	{
		widget->Tick(this->deltaTime);
		widget->Draw();
	}
	//std::cout << "Objects in window: " << Objects.size() << std::endl;
	if(this->appType == Editor)
		ImGui::SFML::Render(*this->window);
	this->window->display();
}

std::list<CObject*>::iterator CEngine::CreateText(std::list<CObject*>::iterator parentObject, std::string text, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelay, float lineSpacing, sf::Color textColor, sf::Text::Style textStyle)
{
	position = ScalePosition(position); size = ScalePosition(size); 
	TextBlock *newText = new TextBlock(this->Objects, parentObject, text, position, size, pathToFont, fontSize, appearingDelay, lineSpacing, textColor, textStyle);
	newText->SetEngine(this);
	return parentObject;
}

void CEngine::CreateWidget(Widget* widgetToCreate)
{
	widgetToCreate->SetEngine(this);
	widgetToCreate->ReadFromFile();
	widgetToCreate->OnConstruct();

	this->widgets.push_back(widgetToCreate);
}

void CEngine::CreateAnimation(Animation* anim, std::string pathToFile)
{
	anim->SetEngine(this);
	this->animations.push_back(anim);
}

void CEngine::DeleteAnimation(Animation* anim)
{

}

sf::Vector2f CEngine::ScalePosition(sf::Vector2f oldPosition) {
	return sf::Vector2f(oldPosition.x * window->getSize().x, oldPosition.y * window->getSize().y);
}