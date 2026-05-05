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
	target = NULL;
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
* setWeight()
******************************/
//will
void edge::setWeight(int w)
{
	weight = w;

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