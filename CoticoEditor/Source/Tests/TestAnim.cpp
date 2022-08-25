#include "TestAnim.h"
#include "Tests/TWidget.h"
#include "Core/CEngine.h"

TestAnim::TestAnim() 
{
	tex.loadFromFile("Content/Animations/Julia.jpg");
	sprite.setTexture(tex);
	sprite.setScale(.1f, .1f);
}

sf::Drawable& TestAnim::GetForDraw()
{
	return this->sprite;
}

void TestAnim::BeginPlay()
{
	this->animation = PlayAnimation(&sprite, "Content/Animations/Biba.png");
	this->widget = CreateWidget<TWidget>();
	TWidget* Test = dynamic_cast<TWidget*>(widget);
	Test->anim = this->animation;
}
