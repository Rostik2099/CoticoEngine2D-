#pragma once
#include "Core/CObject.h"
#include "UI/UIObject.h"
#include <fstream>

class Widget : public CObject
{
public:
	Widget();
	~Widget();
	void Draw();

	virtual void Tick(float dt) override;
	virtual void OnConstruct();
	void ReadFromFile();

protected:
	template<typename Type>
	Type* Bind(std::string bindableName)
	{
		Type* bindableObject = nullptr;
		for (auto& obj : this->UIObjects)
		{
			if (obj->name == bindableName)
			{
				bindableObject = dynamic_cast<Type*>(obj);
				break;
			}
		}
		if (bindableObject == nullptr)
			std::cout << "Failed to Bind: " << bindableName << std::endl;
		return bindableObject;
	};

private:
	void CreateObject(std::string object, std::list<std::string> properties);

protected:
	std::list<UIObject*> UIObjects;
	std::string pathToFile = "Content/Ruslan.cewidget";
};

