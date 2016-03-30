/*
 * NodeController.cpp
 *
 *  Created on: 27, 2016
 *      Author: dvil4688
 */

#include "NodeController.h"
#include <stdlib.h>

NodeController :: NodeController()
{
	notHipsterInts = new CTECArray<int>(5);
}

NodeController :: ~NodeController()
{
	//TODO Auto-generated destructor stub
}

void NodeController :: testLists()
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
    cout << "Index 1 should be 2 and is: " << numbers.getFromIndex(1);
    
    numbers.removeFromFront();
    numbers.removeFromEnd();
    cout << "Head should be 2 and is: " << numbers.getFront() << endl;
    cout << "End should be 8 and is: " << numbers.getEnd() << endl;

    numbers.removeFromIndex(1);
    cout << "Index of value 8 should be 1 and is: " << numbers.indexOf(8) << endl;
    cout << "Size should be 2 and is: " << numbers.getSize();
}


void checkSorts()
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
    CTECArray<int> numbersInList;
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
}

void NodeController :: start()
{
	testLists();

//	arrayTimer.startTimer();
//
//	for (int index = 0; index < notHipsterInts->getSize(); index++)
//	{
//		notHipsterInts->set(index, (23 * index));
//	}
//
//	for (int index = 0; index < notHipsterInts->getSize(); index++)
//	{
//		cout << "notHipsterInts at index " << index << " contains " << notHipsterInts->get(index) << endl;
//	}
//
//	arrayTimer.stopTimer();
//	arrayTimer.displayTimerInfo();
}
    
}
