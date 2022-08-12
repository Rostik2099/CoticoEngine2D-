#include "Properties.h"

Properties::Properties()
{
}

Properties::~Properties()
{
}

void Properties::Render()
{
	ImGui::Begin("Properties");
	ImGui::Text("Zdes mogla bit vasha reklama");
	ImGui::End();
}
