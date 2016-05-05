//
//  CTECHashTable.h
//  NodeXProject
//
//  Created by Villalobos, Deigen on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_h
#define CTECHashTable_h

#include <stdio.h>
#include "CTECArray.cpp"

template <class Type>
class CTECHashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    Type * internalStorage;
    CTECArray<Type> * internalArray;
    
    int findPosition(const Type & value);
    int handleCollision(const Type & value);
    void updateSize();
public:
    CTECHashTable():
    ~CTECHashTable();
    
    int getSize();
    void add(const Type & value);
    bool remove(const Type& value);
    bool contains(const Type & value);
    };
    
    //find . "(" -name "*.m" -or -name "*.mm" -or -name "*.cpp" -or -name "*.swift" ")" -print0 | xargs -0 wc -l
    
#endif /* CTECHashTable_h */
