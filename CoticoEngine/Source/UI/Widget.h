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

	virtual void Tick() override;

	void ReadFromFile(std::string pathToFile);
protected:
	void Bind(UIObject* objectToBind, std::string bindableName);
private:
	void CreateObject(std::string object, std::list<std::string> properties);

protected:
	std::list<UIObject*> UIObjects;
};

