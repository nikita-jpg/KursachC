#ifndef BASE
#define BASE
#include <vector>
#include <string>

using namespace std;
class Base
{
protected:
	int class_number;
	int status;
	string name;
	Base* parent;
	vector<Base*> children;
public:
	Base(Base* parent, string name, int class_number, int status);
	void printChildren(bool i);
	void printHierarchyTree(bool i, int k);
	void setStatus(int status);
	int getStatus();
	string getName();
	string getPatchItem(string ObjectPath, int iLevel);

	Base* findParent(string name);
	Base* getObject(string objectPath);
	Base* getObjectByRootPath(string objectPath);
	Base* getObjectRoot();
	Base* getChild(string nameChild);
	~Base();
};

#endif