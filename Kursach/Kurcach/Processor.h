#ifndef PROCESSOR
#define PROCESSOR
#include "Base.h"
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

class Processor : public Base
{
	using Base::Base;
	public:
		Processor(Base* parent, string name);
		void p_signal(string& text);
		void p_hendler(string text);
};


#endif 