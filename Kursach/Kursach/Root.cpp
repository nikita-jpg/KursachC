#include "Root.h"
#include "Branch2.h"
#include "Branch3.h"
#include "Branch4.h"
#include <iostream>


void Root::start()
{
	do
	{
		cin >> parent_name;
		if (parent_name != "endtree")
		{
			cin >> name_object >> class_number_object >> status_object;
			parent = this->findParent(parent_name);
			switch (class_number_object)
			{
			case 2:
				new Branch2(parent, name_object, class_number_object, status_object);
				break;

			case 3:
				new Branch3(parent, name_object, class_number_object, status_object);
				break;

			case 4:
				new Branch4(parent, name_object, class_number_object, status_object);
				break;
			}
		}
		else
		{
			parent = NULL;
		}
	} while (parent != NULL);

	this->printChildren();
}

