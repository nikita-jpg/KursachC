#include "Processor.h"

#include <iostream>

using namespace std;

Processor::Processor(Base* parent, string name):Base(parent, name)
{
	this->class_number = 3;
}

void Processor::p_signal(string& text)
{
	text = " Text: " + this->getName() + " -> " + text;
}

void parse(string message, int& oy, int& ox, char& token)
{
	string oyStr;
	string oxStr;

	oyStr = message.substr(0, message.find_first_of("|"));
	oxStr = message.substr(message.find_first_of('|') + 1, message.length() - message.find_first_of('|') - 3);
	token = message[message.length() - 1];


	oy = atoi(oyStr.c_str());
	ox = atoi(oxStr.c_str());
}



void Processor::p_hendler(string message)
{

	char token=' ';
	int oy = 0;
	int ox = 0;
	parse(message, oy, ox, token);
	
	if(('a'<=token && token<='a') || ('A' <= token && token <= 'Z'))
	{
		char buffer[10][11];
		ifstream file;
		file.open("field.txt", ios_base::in);
		for (int i = 0; i < 10; i++)
			for(int j=0;j<11;j++)
			file.get(buffer[i][j]);
	
		file.close();
		
		buffer[oy-1][ox-1] = token;
		int fd = _open("field.txt", O_WRONLY);
		_write(fd, buffer, 109);
		_close(fd);
	}
	else
	{
		ofstream file;
		file.open("field.txt", ios_base::out);
		file << endl << "Not a letter of the Latin alphabet : " << token;
		file.close();
	}
}
