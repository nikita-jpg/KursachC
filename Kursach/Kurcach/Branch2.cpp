#include "Branch2.h"

#include <iostream>

using namespace std;

void Branch2::p_signal(string& text)
{
	text = " Text: " + this->getName() + " -> " + text;
}

void Branch2::p_hendler(string text)
{
	cout << "\n" << "Signal to " << this->getName().c_str() << text;
}
