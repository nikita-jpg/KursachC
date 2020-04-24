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

void Base::printChildren()
{
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
		children[i]->printChildren();
	}
}



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


string Base::getName()
{
	return this->name;
}

void Base::setStatus(int status)
{
	this->status = status;
}


int Base::getStatus()
{
	return status;
}



Base::~Base()
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}



