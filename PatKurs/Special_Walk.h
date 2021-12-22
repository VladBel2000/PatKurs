#pragma once
#include "Headers.h"
#ifndef Special_walk_h
#define Special_walk_h

class Special_Walk
{
private:
    float speed, koef_power;

public:
    Special_Walk()
    {
        time_t now_time = time(NULL);
        koef_power = (int)now_time % 3 + 1;
        speed = (int)now_time % 5 + 12;
    }
    Special_Walk(float p_koef_power)
    {
        time_t now_time = time(NULL);
        koef_power = p_koef_power;
        speed = (int)now_time + 1;
    }
    Special_Walk(Special_Walk* p_Special_Walk)
    {
        koef_power = p_Special_Walk->koef_power;
        speed = p_Special_Walk->speed;
    }
    ~Special_Walk() {}

    float get_koef_power()
    {
        return koef_power;
    }
    int get_rez()
    {
        return (int)koef_power * speed;
    }
    void set_Power(float p_koef_power)
    {
        koef_power = p_koef_power;
    }
};
#endif //Special_walk_h