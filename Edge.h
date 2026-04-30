/***********************************
 * Edge.h
 * Written by Sora Schneider
 ***********************************/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//these are the edges between vertex
//they hold the weights between vertex
//no lists just one point to another
class edge
{
    friend class node;
public:
    edge();
    void connect(node*, node*); //connect a vertex to another may not need
    void setWeight(int); //sets the weight for a edge
    int getWeight(); //shows the weight 
    void getConnection(ostream&); //gets the connection and weight between vertex (ostream)?
private:
    int weight; //we can use -1 to check if valid
};
