#pragma once
#include"ImGui/ImGuiLayer.h"

class Properties : public ImGuiLayer
{
public:
	Properties();
	~Properties();
	virtual void Render() override;
};

