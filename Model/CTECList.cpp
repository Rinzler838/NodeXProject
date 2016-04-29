/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: dvil4688
 */

#include "CTECList.h"
#include <assert.h>
using namespace std;

template <class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

/**
 * Destroys everything in the list.
 */
template <class Type>
CTECList<Type>::~CTECList()
{
	ArrayNode<Type> * current = head;
	while (current->getNext() != nullptr)
	{
		ArrayNode<Type> * temp = current;
		current = current->getNext();
		head = current;
		delete temp;
	}
	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}

/**
 * Returns the size of the list.
 */
template <class Type>
int CTECList<Type>::getSize()
{
	return this->size;
}

/**
 * Returns the front, or head of the list.
 */
template <class Type>
Type CTECList<Type>::getFront()
{
    return head->getValue();
}

/**
 * Returns the end of the list.
 */
template <class Type>
Type CTECList<Type>::getEnd()
{
    return end->getValue();
}

/**
 * Returns the node in the list at the given index.
 */
template <class Type>
Type CTECList<Type>::getFromIndex(int index)
{
	//******************************************//
	//	Check to make sure index > 0 & <= size	//
	//	Create a reference to head				//
	//	Get front if index is 0					//
	//	Loop to index							//
	//	Update pointer to the next				//
	//	Return the pointer to the desired Node	//
	//******************************************//
    
    assert(this->size > 0);
	assert(index >= 0 && index < size);

	ArrayNode<Type> * current = head;
    Type returnValue;
    
	if (index == 0)
	{
		getFront();
	}
	else if (index == size -1)
	{
		getEnd();
	}
	else
	{
		for (int spot = 0; spot <= index; spot++)
		{
            if (spot == index)
            {
                returnValue = current->getValue();
            }
			current = current->getNext();
		}
		return returnValue;
	}
}

/**
 * Adds a new Node to the front, or head of the list if the list is not empty.
 */
template <class Type>
void CTECList<Type>::addToFront(const Type& value)
{
	assert(size >= 0);

	ArrayNode<Type> * newNode = new ArrayNode<Type>(value, head);
	head = newNode;
	this->calculateSize();
}

/**
 * Adds a new Node to the end of the list if the list isn't empty.
 * Calculates list size.
 */
template <class Type>
void CTECList<Type>::addToEnd(Type value)
{
    ArrayNode<Type> * newStuff;
    if (end == nullptr)
    {
        addToFront(value);
    }
    else
    {
        newStuff = new ArrayNode<Type>(value);
        end->setNext(newStuff);
    }
    end = newStuff;
    
	this->calculateSize();
}

/**
 * Adds a new Node at the given index if the list is not empty.
 * Calculates list size.
 */
template <class Type>
void CTECList<Type>::addAtIndex(int index, Type value)
{
	assert(index >= 0 && index < size);

	if (index == 0)
	{
		addToFront(value);
	}
	else if (index == size -1)
	{
		addToEnd(value);
	}
	else
	{
        ArrayNode<Type> * insertedNode = new ArrayNode<Type>(value);
        ArrayNode<Type> * current = head;
		for (int spot = 0; spot < index; spot ++)
		{
			current = current->getNext();
		}
		insertedNode->setNext(current->getNext());
		insertedNode->setNext(insertedNode);
	}
	this->calculateSize();
}

/**
 * Removes a Node from the front, or head of the list, given the list is not empty.
 * Calculates list size.
 */
template <class Type>
Type CTECList<Type>::removeFromFront()
{
	Type returnValue;
	assert(size > 0);
	//Create a pointer to what is after head:
	ArrayNode<Type> * newHead;
	newHead = head->getNext();
	//Get what was in the head node
	returnValue = this->head->getValue();
	//Delete what head is pointing to
	delete this->head;
	//Set head to the new head
	this->head = newHead;

	this->calculateSize();
	return returnValue;
}

/**
 * Removes a Node from the end of the list, if the list is not empty.
 * Calculates list size.
 */
template <class Type>
Type CTECList<Type>::removeFromEnd()
{
	//**************************************************//
	//	Check for size == 1, it is a special case		//
	//	Loop over size									//
	//	or												//
	//	Loop until getNext() == nullptr					//
	//	Grab value from the last node					//
	//	Set the next to last node to point to nullptr	//
	//	Set the next to last node as end				//
	//	Delete the old last node						//
	//	Before return the variable call calculateSize()	//
	//	Return value									//
	//**************************************************//

	assert(size > 0);
    
	Type returnValue;

	if (size == 1)
	{
        ArrayNode<Type> * toRemove = end;
        returnValue = removeFromFront();
		end = nullptr;
        head = nullptr;
        delete toRemove;
	}
    else
    {
        ArrayNode<Type> * current = head;
        for (int index = 0; index < size - 1; index++)
        {
            current = current->getNext();
        }
        returnValue = end->getValue();
        delete end;
        current = end;
        current->setNext(nullptr);
    }
	this->calculateSize();
    
	return returnValue;
}

/**
 * Removes a Node from the spot at the given index if the list isn't empty.
 * Calculates list size.
 */
template <class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
	//Check that not removing from an empty list
	assert(this->size > 0);
    
	//Check that index is in bounds
	assert(index >= 0 && index < size);
    
	//Declare a variable to the type to return
	Type thingToRemove;
    
	//Create references
    ArrayNode<Type> * previous;
    ArrayNode<Type> * deleteMe;
    ArrayNode<Type> * newNext;

	if (index == 0)
	{
		thingToRemove = removeFromFront();
	}
	else if (index == size - 1)
	{
		thingToRemove = removeFromEnd();
	}
	else
	{
        ArrayNode<Type> * current = head;
		for (int spot = 0; spot < index + 1; spot++)
		{
            if (spot == index - 1)
            {
                previous = current;
            }
            else if (spot == index)
            {
                deleteMe = current;
                newNext = current->getNext();
            }
		}
        thingToRemove = deleteMe->getValue();
        previous->setNext(newNext);
        delete deleteMe;
        
        this->calculateSize();
	}
	return thingToRemove;
}

template <class Type>
int CTECList<Type> :: indexOf(Type searchValue)
{
    assert (this->size > 0);
    int index = -1;
    ArrayNode<Type> * searchPointer = head;
    
    for (searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer->getNext())
    {
        if (searchValue == searchPointer->getValue())
        {
            return index;
        }
        index++;
    }
    index = -1;
    
    return index;
}

/**
 * Calculates the size of the list by iterating over all nodes in the list.
 */
template <class Type>
void CTECList<Type> :: calculateSize()
{
	assert(size >= 0);

	ArrayNode<Type> * counterPointer = head;
	int count = 0;

	if (counterPointer == nullptr)
	{
		this->size = 0;
		return;
	}
	else
	{
		count++;
		while (counterPointer->getNext() != nullptr)
		{
			counterPointer = counterPointer->getNext();
			count++;
		}
		this->size = count;
	}
}

/**
 * Sets data members to their proper values.
 */
template <class Type>
Type CTECList<Type> :: set(int index, Type value)
{
	assert(index < size && index >= 0);

	ArrayNode<Type> * current = head;
	for (int spot = 0; spot <= index; spot++)
	{
		if (spot != index)
        {
            current = current->getNext();
        }
        else
        {
            current->setValue(value);
        }
    }
}

template <class Type>
void CTECList<Type> :: swap(int indexOne, int indexTwo)
{
    assert (indexOne < size && indexTwo < size);
    
    Type temp = getFromIndex(indexOne);
    set(indexOne, getFromIndex(indexTwo));
    set(indexTwo, temp);
}
    
template <class Type>
void CTECList<Type> :: selectionSort()
{
    int innerLoop, outerLoop;
    
    for (outerLoop = 0; outerLoop < this->size - 1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        for (innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if (getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
            {
                selectedMinimum = innerLoop;
            }
        }
        if (selectedMinimum != outerLoop)
        {
            swap(outerLoop, selectedMinimum);
        }
    }
}
