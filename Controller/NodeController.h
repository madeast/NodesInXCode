/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: emad6932
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include <string>
#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.h"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.h"
#include "../Model/CTECArray.cpp"
#include "../Model/Timer.h"
#include "../Model/CtecList.cpp"
using namespace std;

class NodeController
{
private:
CTECArray<int> * notHipsterInts;
CtecList<int> * numbers;
Timer arrayTimer;
void testsLists();
void checkSorts();


public:
	NodeController();
	virtual ~NodeController();

	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
