/************************************
 * Node.cpp
 * Written by YOUR NAME GOES HERE
 ************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Node.h"
#include "Edge.h"

/******************************
 * Null constructor
 ******************************/

node::node()
{
	int i;

	numT = 0; 
	value = "";

	for (i = 0; i < Edge_MAX; i++)
		edges[i] = NULL;

}

/******************************
 * setValue()
 ******************************/

void node::setValue(string arg)
{

}


/******************************
 * getValue()
 ******************************/

string node::getValue()
{

}

/******************************
 * connect()
 ******************************/
// will
void node::connect(node* t, int w)
{
	if (numT < Edge_MAX)
	{
		edges[numT] = new edge();
		edges[numT]->setTarget(t);
		edges[numT]->setWeight(w);
		numT++;
	}
	else
	{
		cout << "Error no space for new connections" << endl;
	}


}


/******************************
* put()
******************************/
// will
void node::put(ostream& out)
{


}
