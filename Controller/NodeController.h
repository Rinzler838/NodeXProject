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

#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp"
#include "../Model/CTECList.cpp"
#include "../Model/CTECBinaryTree.cpp"
#include "../Model/Graph.cpp"
#include "../Model/Timer.cpp"
#include "../Model/CTECHashTable.cpp"
#include "../Model/HashNode.cpp"

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
    void merge(int data [], int sizeOne, int sizeTwo);
    
    void tryGraph();
    void tryTree();
    
    void testHashTable();
public:
    NodeController();
	virtual ~NodeController();
	void start();
};
#endif /* CONTROLLER_NODECONTROLLER_H_ */
