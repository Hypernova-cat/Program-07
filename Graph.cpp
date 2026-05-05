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
    return false;
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
    node temp;

	in.open(arg, ios::in);

	while (!in.eof())
	{
		in >> source >> target >> distance;

		if (in.good())
		{
          // test param
            cout << source << " -> " << target << "   " << distance << endl;
           
		}

        i = 0;

        // test if source exist in array
        while (i < nodes && vertex[i]->getValue() != source)
        {
            i++;
        }
        s = i;
        //gets to this point in 1st loop
        if (i = nodes && vertex[i]->getValue() != source) // node not found in array test
        {
            temp.setValue(source);
            vertex[i] = &temp;
            nodes++;
        }

        i = 0;

        // test if target exist in array
        while (i < nodes && vertex[i]->getValue() != target)
        {
            i++;
        }
        t = i;
        //gets to this point in 1st loop
        if (i = nodes && vertex[i]->getValue() != target) // node not found in array test
        {
            
            temp.setValue(target);
            vertex[i] = &temp;
            nodes++;
        }
        
        vertex[s]->connect(vertex[t], distance);
        
	}
    in.close();
    return true;
}

/******************************
 * path();
 ******************************/

int graph::path(ostream& out, string source, string target)
{
    return 42;
}