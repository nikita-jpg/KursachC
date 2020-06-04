#ifndef ROOT
#define ROOT

#include "Base.h"
#include <string>
using namespace std;

class Root :public Base
{
private:
	int class_number_object;
	int status_object;
	string name_object;
	string parent_name;
public:
	using Base::Base;
	void start();
	void searchObjects();
};
#endif
