#pragma once
#include "IMGui/ImGuiLayer.h"
#include "UI/Widget.h"

class ElementsList : public ImGuiLayer 
{
public:
	ElementsList();
	virtual void Render() override;
	int selectedElement;
	Widget* currentWidget;
};

