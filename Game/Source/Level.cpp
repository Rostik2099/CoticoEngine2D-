#include "Level.h"
#include "Core/CEngine.h"
#include "Widgets/MainMenuWidget.h"
#include "Widgets/DownMenuWidget.h"

void Level::BeginPlay()
{
	this->BG = new BackGround;
	GetEngine()->AddObject(BG);
	this->currentWidget = CreateWidget<MainMenuWidget>();
	MainMenuWidget* menu = static_cast<MainMenuWidget*>(currentWidget);
	menu->curLvl = this;
}

void Level::ReadLevel(std::string levelName, std::list<std::pair<std::string, std::string>>& params)
{
	std::ifstream fin;
	std::string path = "Content/Levels/";
	path += levelName + ".celevel";
	fin.open(path);
	if (fin.is_open())
	{
		std::string line;
		while (!fin.eof())
		{
			line = "";
			std::getline(fin, line);
			if (line[0] == '#')
			{
				break;
			}
			else
			{
				if (line != "")
				{
					int propEnd = line.find_first_of("=");
					int valueStart = line.find_first_of("=") + 1;
					std::string prop = line.substr(0, propEnd);
					std::string value = line.substr(valueStart, line.length() - valueStart);
					params.push_back(std::make_pair(prop, value));
				}
			}
		}
	}
	else std::cout << "Can't open file: " << path << std::endl;
	fin.close();
}

void Level::OpenLevel(std::string lvlName)
{
	std::list<std::pair<std::string, std::string>> params;
	ReadLevel(lvlName, params);

	for (auto param : params)
	{
		if (param.first == "type")
		{
			if (param.second == "MainMenu")
			{
				currentWidget->Destroy();
				currentWidget = CreateWidget<MainMenuWidget>();
				MainMenuWidget* mm = static_cast<MainMenuWidget*>(currentWidget);
				mm->curLvl = this;
			}
			if (param.second == "default")
			{
				if (currentLvlType != param.second)
				{
					currentWidget->Destroy();
					currentWidget = CreateWidget<DownMenuWidget>();
					DownMenuWidget* newWidget = static_cast<DownMenuWidget*>(currentWidget);
					newWidget->level = this;
				}
			}
			currentLvlType = param.second;
		}

		if (param.first == "bgImage")
		{
			this->BG->ChangeBG(param.second);
		}

		if (currentLvlType == "default")
		{
			DownMenuWidget* newWidget = static_cast<DownMenuWidget*>(currentWidget);
			if (param.first == "leftText")
				newWidget->leftText->UpdateTextBlock(param.second);
			if (param.first == "rightText")
				newWidget->rightText->UpdateTextBlock(param.second);
			if (param.first == "leftLevel")
				newWidget->leftLevel = param.second;
			if (param.first == "rightLevel")
				newWidget->rightLevel = param.second;
			if (param.first == "mainText")
			{
				newWidget->mainText->UpdateTextBlock(param.second);
			}
		}
	}
}
