/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: emad6932
 */

#include "NodeController.h"

using namespace std;

NodeController::NodeController()
{
//	this->myNode.setValue(5);
//	this->stringArrayNode.setValue("words are fun");
	notHipsterInts = new CTECArray<int>(5);
	numbers = new CtecList<int>();
}

NodeController::~NodeController()
{
	// TODO Auto-generated destructor stub
}

void NodeController :: testsLists()
{
	numbers->addToFront(3);
	numbers->addToEnd(8);
	cout << "End should be 8 and is: " << numbers->getEnd() << endl;
}

void NodeController :: start()
{

	testsLists();

	arrayTimer.startTimer();

	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
			notHipsterInts->set(index, (23 * index));
	}

	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		cout << "notHipsterInts at index " << index << " contains " << notHipsterInts->get(index) << endl;
	}

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
}

void NodeController::checkSorts()
{
    /*
     Create an array and list
     Fill each with random data
     sort and time
     rept with ordered data
     print results
     */
    
    CTECArray<int> numbersInArray(5);
    CtecList<int> numbersInList;
    for(int spot = 0; spot < 5000; spot++)
    {
        int randomValue = rand();
        numbersInArray.set(spot, randomValue);
        numbersInList.addToEnd(randomValue);
    }
    
}


