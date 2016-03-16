/*
7 * NodeController.h
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
	CTECArray<int> * notHipsterInts;
	CTECList<int> * numbers;
	Timer arrayTimer;
	void testLists():
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
