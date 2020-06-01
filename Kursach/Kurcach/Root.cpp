#include "Root.h"
#include "Branch2.h"
#include "Branch3.h"
#include "Branch4.h"
#include "Branch5.h"
#include "Branch6.h"
#include <iostream>

Root::Root(Base* parent) :Base(parent, "root")
{
	this->class_number = 1;
}
Root::Root(Base* parent, string name) : Base(parent, name)
{
	this->class_number = 1;
}


int Root::exec_app()
{
	this->buildConnects();
	this->showTree();
	this->showConnects();
	this->initSignals();
	return 0;
}

void Root::start()
{
	string objectPath;
	string name_root;
	Base* par = NULL;

	cin >> name_root;
	this->name = name_root;

	do
	{
		cin >> objectPath;
		if (objectPath != "endtree")
		{
			cin >> name_object >> class_number_object >> status_object;
			par = this->findParent(objectPath);
			switch (class_number_object)
			{
			case 2:
				new Branch2(par, name_object);
				break;

			case 3:
				new Branch3(par, name_object);
				break;
			}
		}
		else
		{
			par = NULL;
		}
	} while (par != NULL);
}

void Root::searchObjects()
{
	string objectPath;
	cin >> objectPath;

	while (objectPath != "//")
	{
		cout << "\n";

		Base* obj = getObject(objectPath);

		if (obj != NULL)
		{
			cout << objectPath << " Object name: " << obj->getName().c_str();
		}
		else
		{
			cout << objectPath << " Object not found";
		}

		cin >> objectPath;
	}
}

//Новое
void Root::buildConnects()
{
	int number;
	string nameSignaling, nameTarget;
	Base* objectSignaling = NULL;
	Base* objectTarger = NULL;
	T_SIGNAL signal;
	T_HENDLER hendler;


	cin >> number;

	while (number != 0)
	{
		cin >> nameSignaling >> nameTarget;

		objectSignaling = this->findParent(nameSignaling);
		objectTarger = this->findParent(nameTarget);

		objectSignaling->set_connect(Root::getSignal(objectSignaling->getClassNumber()),
			objectTarger, Root::getHendler(objectTarger->getClassNumber()));

		Note* note = new Note;
		note->number = number;
		note->nameSignal = nameSignaling;
		note->nameTarget = nameTarget;

		history.push_back(note);

		cin >> number;
	}
}

void Root::showConnects()
{
	cout << "\nSet connects";

	for (int i = 0; i < history.size(); i++)
	{
		cout << "\n" << history[i]->number << " " << history[i]->nameSignal
			<< " " << history[i]->nameTarget;
	}
}
void Root::initSignals()
{
	string nameObject, message;
	Base* objectSignalling = NULL;

	cout << "\nEmit signals";

	cin >> nameObject;

	while (nameObject != "endsignals")
	{
		cin >> message;
		objectSignalling = this->findParent(nameObject);
		objectSignalling->emit_signal(
			Root::getSignal(objectSignalling->getClassNumber()), message);

		cin >> nameObject;
	}
}

T_SIGNAL Root::getSignal(int classNumber)
{
	switch (classNumber)
	{
	case 1:
		return SIGNAL_D(Root, p_signal);
	case 2:
		return SIGNAL_D(Branch2, p_signal);
	case 3:
		return SIGNAL_D(Branch3, p_signal);
	}
}

T_HENDLER Root::getHendler(int classNumber)
{
	switch (classNumber)
	{
	case 1:
		return HENDLER_D(Root, p_hendler);
	case 2:
		return HENDLER_D(Branch2, p_hendler);
	case 3:
		return HENDLER_D(Branch3, p_hendler);
	}
}

Root::~Root()
{
	for (int i = 0; i < history.size(); i++)
	{
		delete history[i];
	}
}
//К_Новое