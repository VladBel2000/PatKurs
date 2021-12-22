#ifndef Types_moves_h
#define Types_moves_h
#include "Type_move.h"
#include "Headers.h"


class Auto : public Type_move
{
public:
	int get_speed() override
	{
		time_t now_time = time(NULL);
		int speed = int(now_time) % 40 + 30;
		return speed;
	}
};

class Walk : public Type_move
{
public:
	int get_speed() override
	{
		time_t now_time = time(NULL);
		int speed = int(now_time) % 5 + 10;
		return speed;
	}
};

class Bicycle : public Type_move
{
public:
	int get_speed() override
	{
		time_t now_time = time(NULL);
		int speed = int(now_time) % 20 + 20;
		return speed;
	}

};
#endif // !Types_moves_h