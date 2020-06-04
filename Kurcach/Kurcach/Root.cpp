#include "Root.h"
#include "Branch2.h"
#include "Branch3.h"
#include "Branch4.h"
#include "Branch5.h"
#include "Branch6.h"
#include <iostream>


void Root::start()
{
	string objectPath;
	Base* par = NULL;
	do
	{
		cin >> objectPath;
		if (objectPath != "endtree")
		{
			cin >> name_object >> class_number_object >> status_object;
			par = this->getObject(objectPath);
			switch (class_number_object)
			{
			case 2:
				new Branch2(par, name_object, class_number_object, status_object);
				break;

			case 3:
				new Branch3(par, name_object, class_number_object, status_object);
				break;

			case 4:
				new Branch4(par, name_object, class_number_object, status_object);
				break;

			case 5:
				new Branch5(par, name_object, class_number_object, status_object);
				break;

			case 6:
				new Branch6(par, name_object, class_number_object, status_object);
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
			cout << objectPath << "     Object name: " << obj->getName().c_str();
		}
		else
		{
			cout << objectPath << "     Object not found";
		}

		cin >> objectPath;
	}
}