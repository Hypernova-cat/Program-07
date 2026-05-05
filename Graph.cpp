/************************************
 * Graph.cpp
 * Written by YOUR NAME GOES HERE
 ************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Graph.h"
#include "Node.h"

/******************************
 * Null constructor
 ******************************/

graph::graph()
{
    int i;
    nodes = 0;

    for (i = 0; i < MAX; i++)
        vertex[i] = NULL;

}

/******************************
 * Null Un-constructor
 ******************************/

graph::~graph()
{

}

/******************************
 * show();
 ******************************/

void graph::show(ostream& out)
{

}
/******************************
 * move();
 ******************************/

bool graph::move(ostream& out, string arg)
{

}

/******************************
 *  depth();
 ******************************/

void graph::depth(ostream& out)
{

}

/******************************
 *  breadth();
 ******************************/

void graph::breadth(ostream& out)
{

}

/******************************
 *  load();
 ******************************/
bool graph::load(string arg)
{
	string source, target;
	int distance, i, s, t;
	fstream in;

   

	in.open(arg, ios::in);

	while (!in.eof())
	{
		in >> source >> target >> distance;

		if (in.good())
		{
          // test param
           
		}

        i = 0;

        // test if source exist in array
        while (i < nodes && vertex[i]->getValue() != source)
        {
            i++;
        }
        s = i;
        if (i = nodes) // node not found in array test
        {
            vertex[i] = new node;
            vertex[i]->setValue(source);
        }

        i = 0;

        // test if target exist in array
        while (i < nodes && vertex[i]->getValue() != target)
        {
            i++;
        }
        t = i;
        if (i = nodes) // node not found in array test
        {
            vertex[i] = new node;
            vertex[i]->setValue(target);
        }
        
        vertex[s]->connect(vertex[t], distance);
        
	}
}

/******************************
 * path();
 ******************************/

int graph::path(ostream& out, string source, string target)
{

}