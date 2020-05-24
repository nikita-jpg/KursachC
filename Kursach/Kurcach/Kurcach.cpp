#include <iostream>
#include <string>
#include "Root.h"
using namespace std;

int main()
{
	Root root(NULL);
	root.start();//Отвечает за создание дерева иерархии
	return root.exec_app();
}
