#ifndef BRUNCH3
#define BRUNCH3
#include "Base.h"

class Branch3 :public Base
{
	using Base::Base;
	public:
	void p_signal(string& text);
	void p_hendler(string text);
};

#endif 