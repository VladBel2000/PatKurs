#pragma once
#ifndef Node_h
#define Node_h
#include "Headers.h"
class Node
{
private:
	string name;
	int x, y;
	vector<Node*> vector_neighbors;
public:
	Node();
	Node(string p_name, int p_x, int p_y);
	string get_name();
	int get_x();
	int get_y();
	vector<Node*> get_vector_neighbors();
	void add_neighbors(Node *p_neighbors);
};
#endif

