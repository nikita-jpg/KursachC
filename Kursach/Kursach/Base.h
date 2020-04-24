#ifndef BASE
#define BASE
#include <vector>
#include <string>

using namespace std;
class Base
{
private:
	int class_number;
	int status;
	string name;
public:
	Base* parent;
	vector<Base*> children;

	Base(Base* parent, string name, int class_number, int status);
	void printChildren();
	void setStatus(int status);
	int getStatus();
	string getName();
	Base* findParent(string name);
	~Base();
};

#endif