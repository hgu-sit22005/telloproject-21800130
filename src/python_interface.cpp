#include <boost/python.hpp>

#include "TelloPro.h"
#include "takeoff.h"
#include "land.h"
#include "up.h"
#include "down.h"
#include "left.h"
#include "right.h"
#include "forward.h"
#include "back.h"
#include "cw.h"
#include "ccw.h"
#include "flip.h"


TelloPro* get_instance(boost::python::str _inst, int _val, char _vall) // int value추가 ; argument를 넣어주기 위해 
{
	std::string instance = boost::python::extract<std::string>(_inst);

	if(instance == "takeoff")
		return new Takeoff;
	else if(instance == "land")
		return new Land;
	else if(instance == "up")
		return new Up(_val); //argument추가 
	else if(instance == "down")
		return new Down(_val);
	else if(instance == "left")
		return new Left(_val);
	else if(instance == "right")
		return new Right(_val);
	else if(instance == "forward")
		return new Forward(_val);
	else if(instance == "back")
		return new Back(_val);
	else if(instance == "cw")
		return new Cw(_val);
	else if(instance == "ccw")
		return new Ccw(_val);
	else if(instance == "flip")
		return new Flip(_vall);
	else
		return nullptr;
}



//추가 없는 부분
BOOST_PYTHON_MODULE(TelloPro)
{
	def("get_instance", get_instance,
			      boost::python::return_value_policy<boost::python::manage_new_object>()); // 3개의 arguments : 파이썬, cpp, return :new호 할당한 objects를 python으로 넘겼을 때 알아서 삭제 하도록
	
	boost::python::class_<TelloPro>("TelloPro") //tellopro라는 class의 method로 get_command...가 있다는 것을 알려줌. 
		.def("get_command", &TelloPro::get_command)
		.def("get_delay", &TelloPro::get_delay);
}

