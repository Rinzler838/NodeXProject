//
//  CTECHashTable.hpp
//  NodeXProject
//
//  Created by Villalobos, Deigen on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include <stdio.h>

template <class Type>
class CTECHashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    Type * internalStorage;
    int findPosition(const Type & value);
    int handleCollision(const Type & value);
    void updateSize();
public:
    CTECHashTable():
    ~CTECHashTable();
    void add(const Type & value);
    bool remove(const Type& value);
    bool contains(const Type & value);
};

#endif /* CTECHashTable_hpp */
