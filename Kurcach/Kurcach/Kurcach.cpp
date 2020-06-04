#include <iostream>
#include <string>
#include "Root.h"
using namespace std;

int main()
{
	string name_root;
	cin >> name_root;
	Root root(NULL, name_root, 1, 1);
	root.start();
	root.printHierarchyTree(true,0);
	root.searchObjects();

	return 0;
}
