#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

class General_functions
{
protected:
	General_functions();
	virtual void Print_info() = 0;
	virtual void Set_all_info() = 0;
	virtual void Set_self_name() = 0;
	virtual string Get_self_name() = 0;

	virtual ~General_functions() = 0;
};
