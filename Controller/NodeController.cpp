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
	
}

NodeController :: ~NodeController()
{
	//TODO Auto-generated destructor stub
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
	testList();
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInfo();
}



void NodeController :: doMergeSort()
{
    mergeData = new int[5000];
    
    for (int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergeSort(mergeData, 5000);
    mergeTimer.stopTimer();
    mergeTimerdisplayTimerInfo();
}

void NodeController :: mergeSort(int data[], int size)
{

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
