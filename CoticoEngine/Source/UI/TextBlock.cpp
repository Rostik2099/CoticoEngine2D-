#include "TextBlock.h"

TextBlock::TextBlock(std::string textStringT, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelayT, float lineSpacing, sf::Color textColor, sf::Text::Style textStyle)
{
    font.loadFromFile(pathToFont);
    text = sf::Text(textStringT, font, fontSize);

    text.setFillColor(textColor);
    text.setStyle(textStyle);
    text.setPosition(position);

    if(text.getLocalBounds().width > size.x) {
        std::list<std::pair<std::string, int>> parcStr = strParcing(textStringT);
        //for(auto &t : parcStr) std::cout << t.first << "\t" << t.second << std::endl;
        std::string str = ""; int i = 0;
        for(auto &t : parcStr) {
            float newPosY = position.y + i * (text.getLocalBounds().height + lineSpacing);
            TextBlock *new_text = new TextBlock(str, newPosY, appearingDelay, text);
            if (new_text->GetText().getLocalBounds().width > size.x) {  
                TextBlock *newText = new TextBlock(str, newPosY, appearingDelay, text);       
                children.push_back(newText);
                str = t.first; str += " "; ++i;
            }
            else {str += t.first; str += " "; delete new_text;}
        }
        UpdateTextBlock("");
        return;
    }



    UpdateTextBlock("");
    textString = textStringT;

    progress = (appearingDelayT == 0) ?  1.0 : 0.0;
    if (progress == 1.0) UpdateTextBlock(textString); 

    if(appearingDelayT < 0) {
        procentSpeed = true;
        appearingDelay = floor(appearingDelayT) * (-1); 
        lastDelay = 0;
    }
    else {
        procentSpeed = false;
        appearingDelay = appearingDelayT;
    }
}

TextBlock::~TextBlock() {}

sf::Drawable& TextBlock::GetForDraw() {
    return text;
}

void TextBlock::Tick() {
    if (progress < 1.0)  {
        if(procentSpeed) {
            if(lastDelay > 0) --lastDelay;
            else {
                UpdateTextBlock(textString.substr(0, ceil(textString.size() * progress)));
                lastDelay = appearingDelay;
                progress += 1.0001 / textString.size();
            }
        }
        else {
            progress += (1.0 / appearingDelay);
            UpdateTextBlock(textString.substr(0, floor(textString.size() * progress)));
        }
    }
}

TextBlock::TextBlock(std::string textStringT, float newPosY, float appearingDelayT, sf::Text textT) {
    text = textT; text.setPosition(sf::Vector2f(text.getPosition().x, newPosY));
    appearingDelay = appearingDelayT;
    UpdateTextBlock(textStringT);
}

void TextBlock::UpdateTextBlock(std::string textStr) {
    text.setString(sf::String::fromUtf8(textStr.begin(), textStr.end()));
}


std::list<std::pair<std::string, int>> TextBlock::strParcing(std::string str) { // тут копируется правда, но я задолбался чинить
    std::list<std::pair<std::string, int>> strs;
    int localSize = 0; int pos = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ' ') {
            strs.push_back(make_pair(str.substr(pos, localSize), localSize));
            for(localSize = 1; i < str.size(); i++) if(str[i] != ' ') break;
            pos = i; 
        }
        else ++localSize;
    }
    strs.push_back(make_pair(str.substr(pos, localSize), localSize));
    return strs;
}

sf::Text TextBlock::GetText() { return text; }