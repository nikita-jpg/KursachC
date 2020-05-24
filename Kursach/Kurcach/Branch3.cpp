#include "Branch3.h"

#include <iostream>

using namespace std;

void Branch3::p_signal(string& text)
{
	text = " Text: " + this->getName() + " -> " + text;
}

void Branch3::p_hendler(string text)
{
	cout << "\n" << "Signal to " << this->getName().c_str() << text;
}