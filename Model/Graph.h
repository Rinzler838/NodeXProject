//
//  Graph.h
//  NodeXProject
//
//  Created by Villalobos, Deigen on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <set>
#include "Graph.cpp"

template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool egdes [MAXIMUM] [MAXIMUM]; //This is the adjacency matrix.
    Type labels [MAXIMUM];
    int manyVertices;
public:
    Graph();
    virtual ~Graph();
    void addVertex(const Type & label);
    void addEdge(int source, int terget);
    void removeEdge(int source, int target);
    Type & operator [] (int vertex);
    int size() const;
    bool isEdge(int source, int target) const;
    std :: set<int> neightbors(int vertex) const;
    Type operator [] (int vertex) const;
};

#endif /* Graph_h */
