#pragma once

#include "ImGui/imgui.h"
#include "ImGui/imgui-SFML.h"

#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class ImGuiLayer
{
public:
	ImGuiLayer();
	~ImGuiLayer();
	
	virtual void Render();
};

