#include "UIObject.h"
#include "UI/Button.h"
#include <string>

void UIObject::Tick() {}

void UIObject::SetProperties(std::list<std::pair<std::string, std::string>> properties){}

UIObject::UIObject() {}

UIObject::~UIObject() {}

TextBlockParams UIObject::GetTextParams(std::list<std::pair<std::string, std::string>> properties)
{
    TextBlockParams params;
    for (auto& p : properties)
    {
        if (p.first == "position")
            params.position = ParseVector2f(p.second);
        if (p.first == "size")
            params.size = ParseVector2f(p.second);
        if (p.first == "text")
            params.text = p.second;
        if (p.first == "fontPath")
            params.fontPath = p.second;
    }
    return params;
}

ButtonParams UIObject::GetButtonParams(std::list<std::pair<std::string, std::string>> properties)
{
    ButtonParams params;
    for (auto& p : properties)
    {
        if (p.first == "position")
            params.position = ParseVector2f(p.second);
        if (p.first == "size")
            params.size = ParseVector2f(p.second);
        if (p.first == "idleColor")
            params.idleColor = ParseColor(p.second);
        if (p.first == "hovColor")
            params.hovColor = ParseColor(p.second);
        if (p.first == "pressedColor")
            params.pressedColor = ParseColor(p.second);
    }
    return params;
}

sf::Color UIObject::ParseColor(std::string value)
{
    int r, g, b, a;

    int start = 0, end;
    for (int i = 0; i < 4; i++)
    {
        int end = value.find_first_of(",", start + 1);
        if (i == 3)
            end = value.length() - start;
        std::string s = value.substr(start, end-start);
        switch (i)
        {
        case 0:
            r = std::stoi(s);
        case 1:
            g = std::stoi(s);
        case 2:
            b = std::stoi(s);
        case 3:
            a = std::stoi(s);
        }
        start = end + 1;
    }

    return sf::Color(r, g, b, a);
}

sf::Vector2f UIObject::ParseVector2f(std::string value)
{
    float a, b;
    int comma = value.find_first_of(",");
    std::string s = value.substr(0, comma);
    a = std::stoi(s);
    s = value.substr(comma + 1, value.length() - comma);
    b = std::stoi(s);
    return sf::Vector2f(a, b);
}

