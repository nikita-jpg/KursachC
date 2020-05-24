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
	//����
	vector <Note*> history;
	//�_�����
	
	void searchObjects();
	int class_number_object;
	int status_object;
	string name_object;
	string parent_name;
public:
	void start();
	//�����
	void p_signal(string& text);
	void p_hendler(string text);
	void buildConnects();
	void showConnects();
	void initSignals();
	//�_�����

	int exec_app();

	~Root();
};
#endif
