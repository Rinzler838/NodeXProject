//
//  Graph.h
//  NodeXProject
//
//  Created by Villalobos, Deigen on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#incluse "Graph.cpp" 

template <class Type>
class Graph
{
private:
    static const int MAXIUMUM = 20;
    
public:
    Graph();
    virtual ~Graph();
    void addVrtex(const Type & label);
    void addEdge(int source, int terget);
    void removeEDdge(int source, int target);
    Type & operator [] (int vertex);
    
};

#endif /* Graph_h */
