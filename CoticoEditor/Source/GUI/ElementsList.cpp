#include "ElementsList.h"
#include "Core/CObject.h"
#include "Tests/TWidget.h"


ElementsList::ElementsList(){}

void ElementsList::Render()
{
	ImGui::Begin("Elements", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	ImGui::End();
}
