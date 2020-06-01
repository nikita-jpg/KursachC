#ifndef ROOT
#define ROOT

#include "Base.h"
#include <string>
#include <vector>

using namespace std;

struct Note
{
	int number;
	string nameSignal;
	string nameTarget;
};


class Root :public Base
{
	using Base::Base;

private:
	//Новое
	vector <Note*> history;
	static T_SIGNAL getSignal(int numberClass);
	static T_HENDLER getHendler(int numberClass);
	//К_Новое
	void searchObjects();
	int class_number_object;
	int status_object;
	string name_object;
	string parent_name;
public:
	Root(Base* parent);
	Root(Base* parent, string name);
	void start();
	//Новое
	void buildConnects();
	void showConnects();
	void initSignals();
	//К_Новое
	int exec_app();

	~Root();
};
#endif
