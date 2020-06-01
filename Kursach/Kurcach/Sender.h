#ifndef SENDER
#define SENDER
#include "Base.h"
#include "Root.h"
#include <fstream>

class Sender :public Base
{
	using Base::Base;
	public:
		Sender(Base* parent, string name);
		void start(int oy, int ox, char token);
		void p_signal(string& text);
		void p_hendler(string text);
};

#endif 