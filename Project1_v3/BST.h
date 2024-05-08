#ifndef BST_H
#define BST_H
#include "Car.h"
#include <list>
#include <fstream>
#include <exception>
#include <vector>
#include <iostream>
#include "Node.h"

class BST
{
public:
	size_t index = 0;		//  count the number of node in binary tree
	BST();
	~BST();
	void insert(Car&);
	Node* search(const string&);		// search by personal key
	void leftNodeRight(int, int = 0);	// use for print the data for each setting: sound, display, general
	void addEleToSave();		// function for add element of binary tree
	void searchByName(string&);	// use for searching node by name
	void searchByKey(string&);	// use for searching node by key
	
private:
	Node* root;
	void insertHelper(Car&, Node*);	// use recursion to insert node to the tree
	Node* searchHelper(const string&, Node*);
	vector<Node*> searchByNameHelper(string&, Node*);
	void searchByKeyHelper(string&, Node*);
	void leftToRightHelper(Node*, int, int&);
	void addToSaveHelper(Node*);
};



#endif // !BST_H
