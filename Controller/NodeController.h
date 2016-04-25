/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: dvil4688
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include <string>

#include "../Model/Node.h"
#include "../Model/ArrayNode.h"
#include "../Model/CTECArray.h"
#include "../Model/CTECList.h"
#include "../Model/Timer.h"

using namespace std;

class NodeController
{
private:
    Timer arrayTimer;
    void sortData();
    void testList();
    void searchList();
    
    void swap(int first, int second);
    void quickSort(int first, int last);
    int partition(int first, int last);
    void doQuick();
    
    void doMergeSort();
    int * mergeData;
    void mergeSort(int data [], int size);
    void merge(int data [], int sizOne, int sizeTwo);
    void tryTree();
public:
    NodeController();
	virtual ~NodeController();
	void start();
};
#endif /* CONTROLLER_NODECONTROLLER_H_ */
