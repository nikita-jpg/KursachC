#include "Sender.h"

#include <iostream>

using namespace std;

Sender::Sender(Base* parent, string name):Base(parent, name)
{
	this->class_number = 2;
}

void Sender::start(int oy,int ox,char token)
{
	string tokenStr(1,token);
	
	string message = std::to_string(oy) + "|" + std::to_string(ox) + "|" + tokenStr; //oy|ox|token
	if( oy >= 0 && ox >=0 && 10 >= oy && 10 >= ox )
	{
		int number = this->getClassNumber();
		this->emit_signal(
			Root::getSignal(this->getClassNumber()), message);
		return;
	}
	else
	{
		ofstream file;
		file.open("field.txt", ios_base::app);
		if (!file.is_open())
			cout << "Not open";
		else
		{
			file << endl<<"Coordinate is wrong ( " << oy << ", " << ox << " )";
			file.close();
		}
	}
}


void Sender::p_signal(string& text)
{
}

void Sender::p_hendler(string text)
{
	FILE* ptrFile = fopen("field.txt", "rt");
	fputs("This is sample.", ptrFile);
	fclose(ptrFile);
	cout << "i am processor";
}