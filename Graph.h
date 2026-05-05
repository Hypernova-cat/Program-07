/***********************************
 * Graph.h
 * Written by Sora Schneider
 ***********************************/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define MAX 50

//this is the graph
//it has a list of vertex and what they are connected to 
//this needs to know what everything is
//has one array of vertx since the nodes has a edge list? <<
//or two arrays one to hold vertex and one to hold all edges?
class graph
{
    friend class node;
public:
    graph();
    ~graph();
    void show(ostream&);
    bool move(ostream&, string);
    void depth(ostream&);
    void breadth(ostream&);
    bool load(string);
    int path(ostream&, string, string);

private:
    node* vertex[MAX];
    int nodes;
};
