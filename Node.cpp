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
		edges[i];

}

/******************************
 * setValue()
 ******************************/

void node::setValue(string arg)
{
	value = arg;
}


/******************************
 * getValue()
 ******************************/

string node::getValue()
{
	return value;
}

/******************************
 * connect()
 ******************************/
// will
void node::connect(node* t, int w)
{
	cout << "node connect\n";
	if (numT < Edge_MAX)
	{
		
		edges[numT]->setTarget(t);
		cout << "node connect\n";
		edges[numT]->setWeight(w);
		cout << "node connect\n";
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
	int i;
	
	out << value << ":" << endl;

	for (i = 0; i < numT; i++)
	{
		out << "\t-> ";  // indent may not be needed
		edges[i]->getConnection(out);  // output from edge
		out << endl;
	}
	out << endl;

}
