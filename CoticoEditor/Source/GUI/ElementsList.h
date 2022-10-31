#pragma once
#include "IMGui/ImGuiLayer.h"
#include "UI/Widget.h"

class Properties;

class ElementsList : public ImGuiLayer 
{
public:
	ElementsList();
	virtual void Render() override;

	Widget* currentWidget;
	Properties* props;
};

