//
//  CTECHashTable.cpp
//  NodeXProject
//
//  Created by Villalobos, Deigen on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECHashTable.h"

template <class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size;
    this->internalStorage = new HashNode<Type>[capacity];
}

template <class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
    delete [] internalStorage;
}

template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size();
}

template <class Type>
void CTECHashTable<Type> :: add(HashNode<Type> currentNode)
{
    if (!contains(currentNode))
    {
        if (this->size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        
        int positionToInsert = findPosition(currentNode);
        
        if (internalStorage[positionToInsert] != nullptr)
        {
            while (internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
            }
            internalStorage[positionToInsert] = currentNode;
        }
        else
        {
            internalStorage[positionToInsert] = currentNode;
        }
    }
}

/*
 * Very basic hashing algorithm
 * Simply assigns a position based on modulo math.
 */
template <class Type>
int CTECHashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    //We are going to "hash" the key the of HashNode to find itsstorage spot.
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}