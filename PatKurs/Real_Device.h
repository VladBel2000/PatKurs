#pragma once
#ifndef Real_Device_h
#include "Device.h"
#include "Type_move.h"
#include "Types_moves.h"
#include "Headers.h"

class Real_Device : public Device
{
private:
	string type_Device;
	int speed;
	Type_move* type_move;
public:
	Real_Device()
	{
		type_Device = "default";
		printf("Initiate type: %s\n", type_Device.c_str());
		type_move = new Walk();
	}
	Real_Device(string p_init)
	{
		type_Device = p_init;
		if (strcmp(p_init.c_str(), (const char*)("Car")) == 0)
			type_move = new Auto();
		else if (strcmp(p_init.c_str(), (const char*)("Walk")) == 0)
			type_move = new Walk();
		else if (strcmp(p_init.c_str(), (const char*)("Bicycle")) == 0)
			type_move = new Bicycle();
	}
	void set_speed(int p_speed)
	{
		speed = p_speed;
	}
	int get_speed()
	{
		return speed;
	}
	void set_type_move(string p_type_move)
	{
		type_Device = p_type_move;
	}
	int get_rez() override
	{
		return type_move->get_speed();
	}
};
#endif // !Real_Device_h