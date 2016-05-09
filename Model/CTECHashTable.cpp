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
    this->internalStorage = new Type[capacity];
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
void CTECHashTable<Type> :: add(const Type & value)
{
    if (!contains(value))
    {
        if (this->size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        
        int positionToInsert = findPosition(value);
        
        if (internalStorage[positionToInsert] != nullptr)
        {
            while (internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
            }
            internalStorage[positionToInsert] = value;
        }
        else
        {
            internalStorage[positionToInsert] = value;
        }
    }
}