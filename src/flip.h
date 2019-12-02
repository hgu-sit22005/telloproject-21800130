#pragma once
#include "TelloPro.h"


class Flip: public TelloPro
{
public:
	Flip();
	Flip(char _val);
	
public:
	double get_delay();
};