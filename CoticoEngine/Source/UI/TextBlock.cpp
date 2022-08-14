#include "TextBlock.h"

TextBlock::TextBlock(std::list<CObject*> &Objects, std::list<CObject*>::iterator &parentObject, std::string textStringT, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelayT, float lineSpacing, sf::Color textColor, sf::Text::Style textStyle)
{
    font.loadFromFile(pathToFont);
    text = sf::Text(textStringT, font, fontSize);

    text.setFillColor(textColor);
    text.setStyle(textStyle);
    text.setPosition(position);

    if(text.getLocalBounds().width > size.x) {
        std::list<std::pair<std::string, int>> parcStr = strParcing(textStringT);
        std::string str = ""; int i = 0;
        for(auto &t : parcStr) {
            float newPosY = position.y + i * (text.getLocalBounds().height + lineSpacing);
            TextBlock *newText = new TextBlock(str, newPosY, appearingDelay, text);
            if (newText->GetText().getLocalBounds().width > size.x) {     
                Objects.insert(parentObject, newText);
                --parentObject;
                str = t.first; str += " "; ++i;
            }
            else {str += t.first; str += " "; delete newText;}
        }
        UpdateTextBlock(""); --parentObject;
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

    Objects.insert(parentObject, this);
    --parentObject;
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

void TextBlock::SetProperties(std::list<std::pair<std::string, std::string>> properties)
{
    TextBlockParams params = GetTextParams(properties);
    this->text.setPosition(params.position);
    this->font.loadFromFile(params.fontPath);
    this->text.setFont(this->font);
    this->text.setString(params.text);
}

void TextBlock::setTransparency(float procent) {
    //sf::Uint8 alfa(unsigned short((procent * 255) % 255));
    if(procent < 0) return;
    text.setColor(sf::Color(text.getColor().r, text.getColor().g, text.getColor().b, ((short)(procent * 255) % 255)));
}

TextBlock::TextBlock(std::string textStringT, float newPosY, float appearingDelayT, sf::Text textT) {
    text = textT; textString = textStringT; text.setString("");
    text.setPosition(sf::Vector2f(text.getPosition().x, newPosY));
    
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