#ifndef ROOT
#define ROOT

#include "Base.h"
#include <string>
using namespace std;

class Root :public Base
{
public:
	using Base::Base;
	int class_number_object;
	int status_object;
	string name_object;
	string parent_name;
	void start();
};
#endif
