#include "Node.h"
Node::Node()
{
	name = "";
	x = 0;
	y = 0;
}
Node::Node(string p_name, int p_x, int p_y)
{
	name = p_name;
	x = p_x;
	y = p_y;
}
string Node::get_name()
{
	return name;
}
int Node::get_x()
{
	return x;
}
int Node::get_y()
{
	return y;
}
vector<Node*> Node::get_vector_neighbors()
{
	return vector_neighbors;
}
void Node::add_neighbors(Node *p_neighbors)
{
	vector_neighbors.push_back(p_neighbors);
}
