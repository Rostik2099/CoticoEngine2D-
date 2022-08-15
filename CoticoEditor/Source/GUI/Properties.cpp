#include "Properties.h"

Properties::Properties() {}

Properties::~Properties(){}

void Properties::Render()
{
	ImGui::Begin("Properties", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	ImGui::InputText("Text", this->buffer, CHAR_MAX);
	ImGui::ColorEdit3("Idle Color", idleColor);
	ImGui::ColorEdit3("Hover Color", hoverColor);
	ImGui::ColorEdit3("Pressed Color", pressedColor);
	ImGui::End();
}

void Properties::Tick()
{
	this->button->idleColor = sf::Color((int)(idleColor[0] * 255), (int)(idleColor[1] * 255), (int)(idleColor[2] * 255));
	this->button->hoverColor = sf::Color((int)(hoverColor[0] * 255), (int)(hoverColor[1] * 255), (int)(hoverColor[2] * 255));
	this->button->pressedColor = sf::Color((int)(pressedColor[0] * 255), (int)(pressedColor[1] * 255), (int)(pressedColor[2] * 255));
}
