/************************************
 * Edge.cpp
 * Written by YOUR NAME GOES HERE
 ************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Edge.h"
#include "Node.h"

/******************************
 * Null constructor
 ******************************/

edge::edge()
{

	target = nullptr;
	weight = -1;

}


/******************************
* setTarget()
******************************/
//will
void edge::setTarget(node* t)
{

	target = t;
}

/******************************
* getTarget()
******************************/
//will
node edge::getTarget()
{
	return *target;
}
/******************************
* setWeight()
******************************/
//will
void edge::setWeight(int w)
{
	this->weight = w;

}
/******************************
* getWeight()
******************************/

int edge::getWeight()
{
	return weight;
}

/******************************
* getConnection()
******************************/
//will
void edge::getConnection(ostream& out)
{
	out << target->getValue();
	out << "\t";
	out << weight;

}