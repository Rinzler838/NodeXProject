/*
 * NodeController.cpp
 *
 *  Created on: 27, 2016
 *      Author: dvil4688
 */

#include "NodeController.h"

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
	numbers->addToFront(3);
	numbers->addToEnd(8);
	cout << "End should be 8 and is: " << numbers->getEnd() <<endl;
	cout << "Head should be 3 and is: " << numbers->getFront() << endl;
}

void NodeController :: start()
{
	testLists();

	arrayTimer.startTimer();

	for (int index = 0; index < notHipsterInts->getSize(); index++)
	{
		notHipsterInts->set(index, (23 * index));
	}

	for (int index = 0; index < notHipsterInts->getSize(); index++)
	{
		cout << "notHipsterInts at index " << index << " contains " << notHipsterInts->get(index) << endl;
	}

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInfo();
}
