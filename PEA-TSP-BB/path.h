//
//  path.h
//  PEA-TSP-BB
//
//  Created by Jakub Sanecki on 06.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#pragma once
#include <ostream>
#include <vector>
#include <string>
#include "edge.h"

using namespace std;

class Path{
public:
    vector<Edge> path;
    
    Path(const Path&);
    Path(const int&);
    Path();
    ~Path();
    Path& operator=(const Path&);
    int getLength();
    void addEdge(Edge);
    friend ostream& operator<<(ostream&, Path&);
    string& generatePath(string&,int,int);
}





