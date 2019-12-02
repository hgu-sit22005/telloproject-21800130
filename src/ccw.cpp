#include "ccw.h"
#include <cstring>
#include <sstream>

Ccw::Ccw()
{
	command = new char[strlen("ccw 60")+1];
	strcpy(command, "ccw 60");
}

Ccw::Ccw(int _value)
{
	std::stringstream sstream;
	sstream<<"ccw "<<_value;

	command = new char[strlen(sstream.str().c_str())+1];
	strcpy(command, sstream.str().c_str());
}

double Ccw::get_delay()
{ 
	return 3; 
}