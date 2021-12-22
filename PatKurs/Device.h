#pragma once
#include "Type_move.h"
class Device
{
protected: Type_move* type_move;
public:
	Device() {}
	~Device() {}

	virtual int get_rez()
	{
		return type_move->get_speed();
	}
};