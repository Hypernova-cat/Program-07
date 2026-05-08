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
    nodes = 0;
    curr = 0;
}


/******************************
 * Null Un-constructor
 ******************************/

graph::~graph()
{
    delete vertex;
}

/******************************
 * show();
 ******************************/

void graph::show(ostream& o)
{
    int i;
    for (i = 0; i < nodes; i++)
    {
        vertex[i]->put(o);
        o << endl;
    }
}

/******************************
 * move();
 ******************************/

bool graph::move(ostream& o, string arg)
{
    int i;

    for (i = 0; i < nodes; i++)
    {
        if (vertex[i]->getValue() == arg)
        {
            curr = i;
            vertex[curr]->put(o);
            return true;
        }

    }
    return false;
}


/******************************
 *  depth();
 ******************************/

void graph::depth(ostream& o)
{
    int i, k;
    if (curr < 0 || curr >= nodes) return;
    o << vertex[curr]->getValue() << endl;

    for ( i = 0; i < Edge_MAX; i++)
    {
        if (vertex[curr]->edges[i] != nullptr)
        {
            vertex[curr]->edges[i]->getConnection(o);
        }
    }
}


/******************************
 *  breadth();
 ******************************/

void graph::breadth(ostream& o)
{
    if (curr < 0 || curr >= nodes) return;

    int i, j;
    bool visited[MAX] = { false };
    int q[MAX];
    int front;
    int rear;
    node* temp;

    front = rear = 0;

    visited[curr] = true;
    q[rear++] = curr;

    while (front < rear)
    {
        int v = q[front++];
        o << vertex[v]->getValue() << " ";
        for (i = 0; i < Edge_MAX; i++)
        {
            if (vertex[v]->edges[i] != nullptr)
            {
                temp = &vertex[v]->edges[i]->getTarget();
                for (j = 0; j < nodes; j++)
                {
                    if (vertex[j] == temp && !visited[j])
                    {
                        visited[j] = true;
                        q[rear++] = j;
                    }
                }
            }
        }
    }
    o << endl;
}


/******************************
 *  load();
 ******************************/
bool graph::load(string arg)
{
	string source, target;
	int distance, i, s, t;
	fstream in;
    //node temp;

	in.open(arg, ios::in);

	while (!in.eof())
	{
        ;
		in >> source >> target >> distance;

		if (in.good())
		{
          // test param
           // cout << source << " -> " << target << "   " << distance << endl;
           
		}

        i = 0;

        // test if source exist in array
        while (i < nodes && vertex[i]->getValue() != source)
        {
            i++;
        }
        s = i;
        //gets to this point in 1st loop
        if (i == nodes ) // node not found in array test
        {
            vertex[i] = new node();
            vertex[i]->setValue(source);
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
        if (i == nodes ) // node not found in array test
        {
            vertex[i] = new node();
            vertex[i]-> setValue(target);
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
    bool v[MAX] = { false };
    int i, j, k, distance , s , t, c;
    node temp;
    k = 1000;
    s = t = -1; // flags to see if they exist in the array
    distance = 0;
    for (i = 0; i < nodes; i++) // loop to test if the points are in the array.
    {
        if (vertex[i]->value == source) s = i;
        if (vertex[i]->value == target) t = i;
    }

    if (s == -1 || t ==-1) return -1; // break out if either not in array
    if (vertex[s]->numT == 0)
    {
        out << "No Paths from : " << source << endl;
        return -1;
    }
    for (i = 0; i < vertex[s]->numT; i++)
    {
        j = vertex[s]->edges[i]->getWeight();
       temp = vertex[s]->edges[i]->getTarget();

       if (temp.getValue() == target)
       {
           out << "Direct path from : " << source << " ->" << target << endl;
           out << "distance : " << j << endl;
           return j;// target found in loop
       }
           

       if (j< k)
       {
           t = i;
           k = j;
       }
    }
    //head of path
   
    temp = vertex[s]->edges[t]->getTarget();
    out << source << " -> ";
    for (i = 0; i < nodes; i++) // find lowest cost path node's index
    {
        if (vertex[i]->value == temp.value)
        {
            v[i] = true;
            s = i; //update source index to continue the path from the new spot.
        }
    }
    //----
    // loop to find a path ======================================================
    while (vertex[s]->numT > 0)
    {
        distance += k;
        out << vertex[s]->getValue() << " -> ";

        k = 1000; // reset k value


        for (i = 0; i < vertex[s]->numT; i++)
        {
            j = vertex[s]->edges[i]->getWeight();
            temp = vertex[s]->edges[i]->getTarget();

            if (temp.getValue() == target)
            {
                distance += j;
                out << temp.getValue() << endl;
                out << "distance : " << distance << endl;
                return distance; // target found in loop
            }


            if (j < k)
            {
                t = i;
                k = j;
            }
        }


        temp = vertex[s]->edges[t]->getTarget();

        for (i = 0; i < nodes; i++) // find lowest cost path node's index
        {
            if (vertex[i]->value == temp.value) s = i; //update source index to continue the path from the new spot.
        }

    }
    




    return -1;
}