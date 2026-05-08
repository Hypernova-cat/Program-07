/***********************************
 * Node.h
 * Written by Sora Schneider
 ***********************************/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Edge.h"
#define Edge_MAX 50
using namespace std;

//nodes are the vertex they know what they connect to
//we need a list to hold what values they are connected too?
//they also have a value like A
//
class node
{
public:
    friend class graph;
    friend class edge;
    node();
    void setValue(string); //set value 
    string getValue();    //return value
    void connect(node*, int);  //connect the vertexs ---added the weight as a param
    void put(ostream&);   //show values and the connection
private:
    string value;
    edge* edges[Edge_MAX];
    int numT;                   // the number of connections and the next open space for an edge
};
