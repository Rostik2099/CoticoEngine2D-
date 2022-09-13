#include "ElementsList.h"
#include "Core/CObject.h"
#include "Properties.h"
#include "Tests/TWidget.h"


ElementsList::ElementsList(){}

void ElementsList::Render()
{
	ImGui::Begin("Elements", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	for (auto elem : this->currentWidget->GetUIObjects())
	{
		std::string fullName = elem->name;
		fullName += " [";
		fullName += elem->type;
		fullName += "]";
		if (ImGui::Button(fullName.c_str(), ImVec2(200, 20)))
		{
			this->props->SetCurrentElement(elem);
		}
	}
	ImGui::End();
}
