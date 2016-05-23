/*
 * NodeController.cpp
 *
 *  Created on: 27, 2016
 *      Author: dvil4688
 */

#include "NodeController.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

NodeController :: NodeController()
{
    
}

NodeController :: ~NodeController()
{
	//TODO Auto-generated destructor stub
}

void NodeController :: start()
{
    testHashTable();
}

void NodeController :: searchList()
{
    
}

void NodeController :: testList()
{
    CTECList<int> numbers;
    
    numbers.addToFront(3);
    numbers.addToEnd(8);
    numbers.addToFront(0);
    numbers.addToEnd(2);
    cout << "Head should be 0 and is: " << numbers.getFront() << endl;
	cout << "End should be 2 and is: " << numbers.getEnd() <<endl;
    cout << "Size should be 4 and is: " << numbers.getSize() << endl;
    
    numbers.addAtIndex(1, 2);
    cout << "Index 1 should be 2 and is: " << numbers.getFromIndex(1) << endl;
    
    numbers.removeFromFront();
    numbers.removeFromEnd();
    cout << "Head should be 2 and is: " << numbers.getFront() << endl;
    cout << "End should be 8 and is: " << numbers.getEnd() << endl;

    numbers.removeFromIndex(1);
    cout << "Index of value 8 should be 1 and is: " << numbers.indexOf(8) << endl;
    cout << "Size should be 2 and is: " << numbers.getSize();
}


void NodeController :: sortData()
{
    /*
      Create list of Array
      Fill with random data
      then...
      Fill with ordered data
    
      Start time
      Sort list
      Stop time
      Print time
     */
    
    CTECArray<int> numbersInArray(5000);
    CTECList<int> numbersInList;
    int cPlusPlusArray[5000];
    
    for (int spot = 0; spot < 5000; spot++)
    {
        int randomValue = rand();
        numbersInArray.set(spot, randomValue);
        numbersInList.addToFront(randomValue);
        cPlusPlusArray[spot] = randomValue;
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    numbersInList.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInfo();
    
    sortTimer.resetTimer();
    
    sortTimer.startTimer();
    std :: sort(std :: begin(cPlusPlusArray), std :: end( cPlusPlusArray));
    sortTimer.stopTimer();
    sortTimer.displayTimerInfo();
    
    sortTimer.resetTimer();
}

void NodeController :: doMergeSort()
{
    mergeData = new int[500000000];
    
    for (int spot = 0; spot < 500000000; spot++)
    {
        int myRandom = rand() % 1000;
        mergeData[spot] = myRandom;
    }
    for (int spot = 0; spot < 5000; spot ++)
    {
        cout << mergeData[spot] << ", ";
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergeSort(mergeData, 500000000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    
    for (int spot = 0; spot < 5000; spot++)
    {
        cout <<mergeData[spot] << ", ";
    }
    delete [] mergeData;
}

void NodeController :: tryTree()
{
    CTECBinaryTree<int> testTree;
    testTree.insert(7);
    testTree.insert(10);
    testTree.insert(-5);
    testTree.insert('4');
    
    cout << testTree.contains('7');
    cout << "\nInorder Traversal " << endl;
    testTree.inorderTraversal(testTree.getRoot());
    cout << "\nPreorder Traversal " << endl;
    testTree.preorderTraversal(testTree.getRoot());
    cout << "\nPostorder Traversal " << endl;
    testTree.postorderTraversal(testTree.getRoot());
    cout << "\nTrees " << endl;
}

void NodeController :: tryGraph()
{
    Graph<int> testGraph;
    testGraph.addVertex(1);
    testGraph.addVertex(2);
    testGraph.addVertex(3);
    testGraph.addVertex(4);
    testGraph.addVertex(5);
    testGraph.addVertex(6);
    testGraph.addVertex(7);
    testGraph.addVertex(8);
    testGraph.addVertex(9);
    testGraph.addVertex(10);
    
    //10 vertices
    //Connect them
    
    testGraph.addEdge(0, 1);
    testGraph.addEdge(1, 2);
    testGraph.addEdge(2, 3);
    testGraph.addEdge(3, 4);
    testGraph.addEdge(4, 5);
    testGraph.addEdge(5, 6);
    testGraph.addEdge(6, 7);
    testGraph.addEdge(7, 8);
    testGraph.addEdge(8, 9);
    testGraph.addEdge(9, 10);
    testGraph.addEdge(1, 10);
    testGraph.addEdge(2, 9);
    testGraph.addEdge(3, 8);
    testGraph.addEdge(4, 7);
    
    cout << "\nDepth-First Traversal " << endl;
    testGraph.depthFirstTraversal(testGraph, 0);
    cout << "\nBreadth-First Traversal " << endl;
    testGraph.breadthFirstTraversal(testGraph, 0);
}

void NodeController :: testHashTable()
{
    CTECHashTable<int> tempTable;
    HashNode<int> tempArray[10];
    
    for (int spot = 0; spot < 10; spot++)
    {
        int randomValue = rand();
        int randomKey = rand();
        HashNode<int> temp = HashNode<int>(randomKey, randomValue);
        tempTable.add(temp);
        tempArray[spot] = temp;
    }
    bool testOne = tempTable.contains(tempArray[0]);
    bool testTwo = tempTable.contains(tempArray[1]);
    bool testThree = tempTable.contains(tempArray[2]);
    bool testFour = tempTable.contains(tempArray[11]);
    bool testFive = tempTable.contains(tempArray[12]);
    bool testSix = tempTable.contains(tempArray[13]);
    string result;
    
    if (testOne)
    {
        result = "Value 1 is here";
    }
    else
    {
        result = "Value 1 is not here";
    }
    cout << result << endl;
    
    if (testTwo)
    {
        result = "Value 2 is here";
    }
    else
    {
        result = "Value 2 is not here";
    }
    cout << result << endl;
    
    if (testThree)
    {
        result = "Value 3 is here";
    }
    else
    {
        result = "Value 3 is not here";
    }
    cout << result << endl;
    
    if (testFour)
    {
        result = "Value 4 is here";
    }
    else
    {
        result = "Value 4 is not here";
    }
    cout << result << endl;
    
    if (testFive)
    {
        result = "Value 5 is here";
    }
    else
    {
        result = "Value 5 is not here";
    }
    cout << result << endl;
    
    if (testSix)
    {
        result = "Value 6 is here";
    }
    else
    {
        result = "Value 6 is not here";
    }
    cout << result << endl;
}

void NodeController :: mergeSort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if (size > 1)
    {
        sizeOne = sizeOne / 2;
        sizeTwo = size - sizeOne;
        
        mergeSort(data, sizeOne);
        mergeSort(data + sizeOne, sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
}

void NodeController :: merge(int data[], int sizeOne, int sizeTwo)  //Merging the split card groups back together
{
    int * temp;     //Link for a temporary array
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while ((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if (data[copied1] < (data + sizeOne)[copied2])      //Smaller goes in small half
        {
            temp[copied++] = data[copied1++];
        }
        else        //Larger goes in large half
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    while (copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while (copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    
    for (index = 0; index< sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController :: quickSort(int first, int last)
{
    int pivotIndex;
    
    if (first < last)
    {
        pivotIndex = partition(first, last);
        quickSort(first, pivotIndex - 1);
        quickSort(pivotIndex + 1, last);
        
    }
}

int NodeController :: partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap (first, (first + last) / 2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for (index = first + 1; index <= last; index++)
    {
        if (mergeData[index] < pivot)
        {
            smallIndex++;
            swap (smallIndex, index);
        }
    }
    swap (first, smallIndex);
    
    return smallIndex;
}

void NodeController :: swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController :: doQuick()
{
    mergeData = new int[500000];
    
    for (int spot = 0; spot < 500000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    quickSort(0, 4999999);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    
    delete [] mergeData;
}
