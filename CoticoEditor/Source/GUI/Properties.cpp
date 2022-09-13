#include "Properties.h"

#include "UI/TextBlock.h"

Properties::Properties() {}

Properties::~Properties(){}

void Properties::ShowButtonParams()
{
};

void Properties::ShowTextParams()
{
	static char TextBuf[255];
	ImGui::InputText("Text", TextBuf, sizeof(TextBuf));

	TextBlock* textBlock = static_cast<TextBlock*>(this->currentElem);
	std::string text(TextBuf);
	textBlock->SetText(text);
};

void Properties::Render()
{
	ImGui::Begin("Properties", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	if (this->currentElem)
	{
		if (this->currentElem->type == "Button")
			ShowButtonParams();
		if (this->currentElem->type == "TextBlock")
			ShowTextParams();
	}
	ImGui::End();
}

void Properties::Tick(){}

void Properties::SetCurrentElement(UIObject* elem)
{
	this->currentElem = elem;
}
