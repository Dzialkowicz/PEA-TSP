//
//  edge.h
//  PEA-TSP-BB
//
//  Created by Jakub Sanecki on 06.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#pragma once
class Edge{
public:
    int startCity;
    int endCity;
    int cost;
    
    Edge();
    ~Edge();
    Edge(int,int,int);
    Edge(const Edge&);
    Edge& operator=(const Edge&);
    bool operator==(Edge&);
}
