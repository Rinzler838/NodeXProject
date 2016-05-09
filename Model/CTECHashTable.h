//
//  CTECHashTable.h
//  NodeXProject
//
//  Created by Villalobos, Deigen on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_h
#define CTECHashTable_h

#include "HashNode.cpp"

template <class Type>
class CTECHashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    HashNode<Type> * internalStorage;
    
    int findPosition(HashNode<Type> currentNode);
    int handleCollision(HashNode<Type> currentNode);
    void updateSize();
    
    int getNextPrime();
    bool isPrime(int candidateNumber);
public:
    CTECHashTable();
    ~CTECHashTable();
    int getSize();
    void add(HashNode<Type> currentNode);
    bool remove(HashNode<Type> currentNode);
    bool contains(HashNode<Type> currentNode);
};
    
    //find . "(" -name "*.m" -or -name "*.mm" -or -name "*.cpp" -or -name "*.swift" ")" -print0 | xargs -0 wc -l
    
#endif /* CTECHashTable_h */
