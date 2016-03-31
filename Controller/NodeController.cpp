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

void NodeController::doMergeSort()
{
    mergeData = new int[500000];
    
    for(int spot = 0; spot < 500000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    
    for (int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 500000);
    mergeTimer.startTimer();
    mergeTimer.displayTimerInformation();
    for (int spot = 0; spot < 50; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    delete [] mergeData;
}

void NodeController::mergesort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size - sizeOne;
        
        mergesort(data, sizeOne);
        mergesort((data + sizeOne), sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp; //Link for a temporary array
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while((copied1 < sizeOne) &&(copied2 < sizeTwo))
    {
        if(data[copied] < (data + sizeOne)[copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController::quickSort(int first, int size)
{
    int pivotIndex;
    
    if(size > 1)
    {
        pivotIndex = partition(first, last);
        quickSort(first, pivotIndex-1);
        quickSort(pivotIndex+1, last);
    }
}

int NodeController::partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    swap(first, smallIndex);
    
    return smallIndex;
}

void NodeController::swap(int first, int second)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}





