#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Car.h"

// class include a data is Car object and Node left and Node right
class Node
{
public:
	Car data;
	Node* leftNode;
	Node* rightNode;

	Node(Car& c) {
		data = c;
		leftNode = nullptr;
		rightNode = nullptr;
	}
	~Node() {}	

};


#endif // !NODE_H
