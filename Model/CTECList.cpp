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
	assert(size > 0);
	return head;
}

/**
 * Returns the end of the list.
 */
template <class Type>
Type CTECList<Type>::getEnd()
{
	assert(size > 0);
	return end;
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

	assert(index >= 0 && index < size);

	ArrayNode<Type> * nodeFromIndex = head;
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
			nodeFromIndex = nodeFromIndex->getNext();
		}
		return nodeFromIndex;
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
	this->calculateSize;
}

/**
 * Adds a new Node to the end of the list if the list isn't empty.
 * Calculates list size.
 */
template <class Type>
void CTECList<Type>::addToEnd(Type value)
{
	assert(size >= 0);

	ArrayNode<Type> * newNode = new ArrayNode<Type>(value, end);
	end = newNode;
	nullptr = newNode->setNext();
	this->calculateSize;
}

/**
 * Adds a new Node at the given index if the list is not empty.
 * Calculates list size.
 */
template <class Type>
void CTECList<Type>::addAtIndex(int index, Type value)
{
	assert(size >= 0);
	assert(index >= 0 && index < size);

	ArrayNode<Type> newNode = new ArrayNode<Type>;
	ArrayNode<Type> * current = newNode;
	ArrayNode<Type> * previous;
	ArrayNode<Type> * next;
	newNode->setValue(value);

	if (index == 0)
	{
		newNode->addToFront();
	}
	else if (index == size -1)
	{
		newNode->addToEnd();
	}
	else
	{
		for (int spot = 0; spot < index; spot ++)
		{
			current = current->getNext();
			previous = previous->getNext();
			next = next->getNext();
		}
		newNode = previous->setNext();
		newNode->setNext(next);
		size++;
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
	Type valueToRemove;
	ArrayNode<Type> * thisNode = getFront();

	if (size == 1)
	{
		valueToRemove = removeFromFront();
		end = nullptr;
		calculateSize();
		return valueToRemove;
	}

	while (thisNode->getNext()->getNext() != nullptr)
	{
		thisNode = thisNode->getNext();
	}
	valueToRemove = thisNode->getNext()->getValue();
	end = thisNode;
	delete thisNode->getNext();

	this->calculateSize();
	return valueToRemove();
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
	ArrayNode<Type> * previous, deleteMe, newNext;

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
		for (int spot = 0; spot < index + 1; spot++)
		{

		}

		size--;
	}

	this->calculateSize();
	return thingToRemove;
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
Type CTECList<Type>::set(int index, Type value)
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
