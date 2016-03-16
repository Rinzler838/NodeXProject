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
public:
	CTECArray(int size);
	virtual ~CTECArray();
	int getSize();
    int indexOf(Type value);
	Type get(int position);
	void set(int position, const Type& value);
};

#endif /* MODEL_CTECARRAY_H_ */
