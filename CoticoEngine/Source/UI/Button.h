#pragma once
#include "UI/UIObject.h"

enum ButtonState { Idle = 0, Hover, Pressed };

class Button : public UIObject
{

public:
	Button();
	~Button();

	virtual sf::Drawable& GetForDraw() override;
	virtual void Tick(float dt) override;
	virtual void SetProperties(std::list<std::pair<std::string, std::string>> properties) override;

	bool isPressed() const;

	template<typename Type>
	void OnClicked(Type* object, void(Type::*func)())
	{

	};

private:
	bool IsMouseOver();

private:
	sf::RectangleShape buttonShape;

	short unsigned buttonState;
public:
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;
};

