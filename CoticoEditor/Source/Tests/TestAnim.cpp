#include "TestAnim.h"

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
