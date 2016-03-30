/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: dvil4688
 */

#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_

#include "ArrayNode.h"

template <class Type>
class CTECArray
{
private:
	int size;
	ArrayNode<Type> * head;
    void swap(int indexOne, int indexTwo);
public:
	CTECArray(int size);
	virtual ~CTECArray();
	int getSize();
    int indexOf(Type value);
    int nextIndexOf(int startingIndex, Type searchValue);
	Type get(int position);
	void set(int position, const Type& value);
    void selectionSort();
};

#endif /* MODEL_CTECARRAY_H_ */
