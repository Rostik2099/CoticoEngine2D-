#include "Widget.h"
#include "UI/Button.h"
#include"UI/TextBlock.h"
#include "Core/CEngine.h"

template<typename Type>
UIObject* SpawnUIObject(std::string objName, std::list<std::pair<std::string, std::string>> properties, CObject* widget)
{
	UIObject* spawnedObject = new Type;
	spawnedObject->SetEngine(widget->GetEngine());
	spawnedObject->name = objName;
	spawnedObject->SetProperties(properties);
	return spawnedObject;
}

Widget::Widget(){  }

Widget::~Widget()
{
	for (auto& object : this->UIObjects)
	{
		delete object;
	}
}

void Widget::Draw()
{
	for (auto& object : this->UIObjects)
	{
		GetEngine()->window->draw(object->GetForDraw());
	}
}

void Widget::Tick(float dt)
{
	for (auto& object : this->UIObjects)
	{
		object->Tick(dt);
	}
}

void Widget::OnConstruct() {}

void Widget::ReadFromFile()
{
	std::ifstream fin;
	fin.open(this->pathToFile);
	if (fin.is_open())
	{
		std::string line;
		std::string object;
		std::list<std::string> properties;
		while (!fin.eof())
		{
			line = "";
			std::getline(fin, line);
			if (line[0] == '#')
			{
				if (object != "")
					CreateObject(object, properties);
				object = line;
				properties.clear();
			}
			else
			{
				if (line != "")
					properties.push_back(line);
			}
		}
	}
	else std::cout << "Can't open file: " << this->pathToFile << std::endl;
	fin.close();
}


void Widget::CreateObject(std::string object, std::list<std::string> properties)
{
	std::list<std::pair<std::string, std::string>> params;
	std::string objName;
	std::string objClass;

	int classEnd = object.find_first_of("=") - 1;
	int nameStart = object.find_first_of("=") + 1;
	objClass = object.substr(1, classEnd);
	objName = object.substr(nameStart, object.length() - nameStart);

	for (auto& pr : properties)
	{
		int propEnd = pr.find_first_of("=");
		int valueStart = pr.find_first_of("=") + 1;
		std::string prop = pr.substr(0, propEnd);
		std::string value = pr.substr(valueStart, pr.length() - valueStart);
		params.push_back(std::make_pair(prop, value));
	}
	
	if (objClass == "Button")
	{
		this->UIObjects.push_back(SpawnUIObject<Button>(objName, params, this));
		return;
	}
	if (objClass == "TextBlock")
	{
		this->UIObjects.push_back(SpawnUIObject<TextBlock>(objName, params, this));
		return;
	}
	else std::cout << "Failed to create UI Object" << std::endl;
}
