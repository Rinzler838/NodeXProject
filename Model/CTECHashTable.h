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
#include "CTECList.cpp"

template <class Type>
class CTECHashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    HashNode<Type> * internalStorage;
    CTECList<HashNode <Type>> * tableStorage;
    
    int findPosition(HashNode<Type> currentNode);//Done
    int findTablePosition(HashNode<Type>);//Done
    int handleCollision(HashNode<Type> currentNode);//Done
    void updateSize();//Done
    void updateTableCapacity();
    int getNextPrime();//Done
    bool isPrime(int candidateNumber);//Done
public:
    CTECHashTable();//Done
    ~CTECHashTable();//Done
    int getSize();//Done
    void add(HashNode<Type> currentNode);//Done
    void addToTable(HashNode<Type> currentNode);//Done
    bool remove(HashNode<Type> currentNode);//Done
    bool contains(HashNode<Type> currentNode);//Done
};
    
    //find . "(" -name "*.m" -or -name "*.mm" -or -name "*.cpp" -or -name "*.swift" ")" -print0 | xargs -0 wc -l
    
#endif /* CTECHashTable_h */
