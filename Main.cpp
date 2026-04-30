/***********************************
 * Program 07
 * Written by Mark M Bowman
 ***********************************/ 

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Graph.h"

/****************************
 * main()
 ****************************/
int main()
{ string fname,s,start,finish;
  char method;
  graph g;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;

// Load file into graph

  if(!g.load(fname)) return 0;
  cout << endl;

// Loop to display graph

  method = 0;

  while(method!='Q')
    {

// Menu

      cout << "S)how, M)ove, D)epth, B)readth, P)ath, Q)uit: ";
      cin >> s;
      method = toupper(s[0]);

// Show

      if(method=='S') g.show(cout);

// Move

      if(method=='M')
        { cout << "Enter node: ";
          cin >> s;
          g.move(cout,s);
        };

// Depth

      if(method=='D') g.depth(cout);

// Breadth

      if(method=='B') g.breadth(cout);

// Path

      if(method=='P')
        { cout << "Enter start node: ";
          cin >> start;
          cout << "Enter finish node: ";
          cin >> finish;
          g.path(cout,start,finish);
        };

// End of main loop

      cout << endl;
    };

// Done

  cout << "Thank you!" << endl;

}
