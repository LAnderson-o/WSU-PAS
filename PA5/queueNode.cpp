#include "queueNode.hpp"

//constructors

QueueNode::QueueNode(Data& newData) {
	pData = new Data(newData);
	pNext = nullptr;
}

QueueNode::~QueueNode() {
	delete pData;
}


//member functions
void QueueNode::decrement() {
	int num = pData->getServiceTime();
	pData->setServiceTime(--num);
}


//getters

Data* QueueNode::getData() {
	return pData;
}

QueueNode* QueueNode::getNext() {
	return pNext;
}


//setters

void QueueNode::setNext(QueueNode* newP) {
	pNext = newP;
}

void QueueNode::setTotalTime(int newTime) {
	pData->setTotalTime(newTime);
}