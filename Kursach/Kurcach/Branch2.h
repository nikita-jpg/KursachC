#ifndef BRUNCH2
#define BRUNCH2
#include "Base.h"

class Branch2 : public Base
{
	using Base::Base;
	public:
		void p_signal(string& text);
		void p_hendler(string text);
};


#endif 