#include "TextBlock.h"

TextBlock::TextBlock(std::string textStringT, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelayT, sf::Color textColor, sf::Text::Style textStyle)
{
    font.loadFromFile(pathToFont);
    text = sf::Text("", font, fontSize);

    text.setFillColor(textColor);
    text.setStyle(textStyle);
    text.setPosition(position);

    textString = textStringT;
    
    progress = (appearingDelayT == 0) ?  1.0 : 0.0;
    if (progress == 1.0) UpdateTextBlock(textString); 
    appearingDelay = appearingDelayT;
}

void TextBlock::UpdateTextBlock(std::string textStr) {
    text.setString(textStr);
}

void TextBlock::AddTick() {
    if (progress < 1.0)  {
        progress += (1.0 / appearingDelay);
        UpdateTextBlock(textString.substr(0, floor(textString.size() * progress)));
    }
}

TextBlock::~TextBlock() {}

sf::Drawable& TextBlock::GetForDraw() {
    return text;
}
