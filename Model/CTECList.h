/*
 * CTECList.h
 *
 *  Created on: Feb 22, 2016
 *      Author: dvil4688
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_

#include "ArrayNode.h"

template <class Type>
class CTECList
{
private:
	int size;
	ArrayNode<Type> * head;
	ArrayNode<Type> * end;
	void calculateSize();
    void swap(int indexOne, int indexTwo);
public:
	CTECList();
	~CTECList();
	int getSize();
	Type getFront();
	Type getEnd();
	Type getFromIndex(int index);
	void addToFront(const Type& value);
	void addToEnd(Type value);
	void addAtIndex(int index, Type value);
	Type removeFromFront();
	Type removeFromEnd();
	Type removeFromIndex(int index);
	Type set(int index, Type value);
    int indexOf(Type searchValue);
    void selectionSort();
};

#endif /* MODEL_CTECLIST_H_ */
