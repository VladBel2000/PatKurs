#pragma once
#include "Headers.h"
#include "Node.h"
#ifndef navigator_h
#define navigator_h


class Navigator { 
private:
    Navigator() {}

public:
    vector<Node> list_node;					// Список исходных вершин
    vector<Node> list_way;					// Список вершин найденного пути
    ~Navigator() {}
    static Navigator* getInstance()
    {
        static Navigator instance;
        return &instance;
    }
    int find_length()
    {
        if (list_way.size() < 2)
            return 0;
        else
        {
            float length = 0;
            for (int i = 0; i < list_way.size() - 1; i++)
            {
                int x_1 = list_way[i].get_x();
                int y_1 = list_way[i].get_y();
                int x_2 = list_way[i + 1].get_x();
                int y_2 = list_way[i + 1].get_y();
                float S = sqrt(pow((x_1 - x_2), 2) + pow((y_1 - y_2), 2));
                length = length + S;
            }
            return (int)length;
        }
    }
};
#endif //navigator_h