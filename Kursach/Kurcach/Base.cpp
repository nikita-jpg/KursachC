#include <iostream>
#include "Base.h"
using namespace std;

Base::Base(Base* parent, string name, int class_number, int status)
{
	this->parent = parent;
	this->class_number = class_number;
	this->status = status;
	this->name = name;
	if (parent != NULL)
	{
		parent->children.push_back(this);
	}
}

void Base::printChildren(bool i)
{
	if (i) cout << "Test result" << endl;
	cout << "The object " << this->getName().c_str();

	if (status > 0)
	{
		cout << " is ready";
	}
	else
	{
		cout << " is not ready";
	}

	for (int i = 0; i < children.size(); i++)
	{
		cout << endl;
		children[i]->printChildren(false);
	}
}

void Base::printHierarchyTree(bool i, int k)
{
	if (i) cout << "Object tree" << endl;
	cout << this->getName().c_str();

	k++;
	for (int i = 0; i < children.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < k; j++)
			cout << "    ";
		children[i]->printHierarchyTree(false, k);
	}
}

//Ищет родителя объекта с уникальным именем
Base* Base::findParent(string name)
{
	Base* element = NULL;
	if (name == this->getName().c_str())
	{
		element = this;
	}
	else
	{
		for (int i = 0; i < children.size(); i++)
		{
			element = children[i]->findParent(name);
			if (element != NULL)
			{
				break;
			}
		}
	}
	return element;
}


//Вырезает название объекта из пути по номеру объекта. Отсчёт с корневого объекта с 1.
string Base::getPatchItem(string objectPath, int iLevel)
{
	int indexStart, indexEnd, iCurrentLevel;

	indexStart = iCurrentLevel = 1;

	while (indexStart)
	{
		indexEnd = objectPath.find("/", indexStart);

		if (iCurrentLevel == iLevel)
			return objectPath.substr(indexStart, indexEnd - indexStart);

		indexStart = indexEnd + 1;
		iCurrentLevel++;
	}

	return "";
}


//Возвращает объект по пути
Base* Base::getObjectByRootPath(string objectPath)
{
	int iLevel = 1;
	string pathItem;
	Base* currentBase = getObjectRoot();
	if (getPatchItem(objectPath, iLevel) != currentBase->getName())
		return NULL;
	iLevel++;
	pathItem = getPatchItem(objectPath, iLevel);
	while (!pathItem.empty())
	{
		currentBase = currentBase->getChild(pathItem);
		if (!currentBase)
			return NULL;
		iLevel++;
		pathItem = getPatchItem(objectPath, iLevel);
	}
	return currentBase;
}


//Работает с 2-мя типами путей. //название, если такой объект единственный, или /путь до объекта
Base* Base::getObject(string objectPath)
{
	if (objectPath[0] == '/' && objectPath[1] == '/')
		return findParent(objectPath.substr(2, string::npos));

	return getObjectByRootPath(objectPath);
}


//Проверяет, есть ли у объекта ребёнок с таким именем
Base* Base::getChild(string nameChild)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i]->name == nameChild)
			return children[i];
	}
	return NULL;
}


string Base::getName()
{
	return this->name;
}

int Base::getStatus()
{
	return status;
}

Base* Base::getObjectRoot()
{
	Base* currentBase = this;
	while (currentBase->parent)
		currentBase = currentBase->parent;
	return currentBase;
}

void Base::setStatus(int status)
{
	this->status = status;
}

Base::~Base()
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}
