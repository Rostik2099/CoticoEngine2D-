#pragma once
#include"ImGui/ImGuiLayer.h"
#include"UI/Button.h"

class Properties : public ImGuiLayer
{
public:
	Properties();
	Button* button;
	~Properties();
	virtual void Render() override;
	virtual void Tick() override;

	float idleColor[3] = { (float)0 / 255, (float)255 / 255, (float)0 / 255};
	float hoverColor[3] = { (float)255 / 255, (float)255 / 255, (float)0 / 255};
	float pressedColor[3] = { (float)0 / 255, (float)0 / 255, (float)255 / 255 };
};

