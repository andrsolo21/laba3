#pragma once
template <typename T>
class Node
{
public:
	enum Color { RED, BLACK };
	Node();
	~Node();
	int getZn();
	T getKey();

	Node * left, *right, *parent;
	T * key;
	Color color;
	int zn;
};

