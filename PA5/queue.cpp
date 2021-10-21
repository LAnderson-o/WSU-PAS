#include "queue.hpp"


//constructors

Queue::Queue(QueueNode* pNewHead, QueueNode* pNewTail) {
	pHead = pNewHead;
	pTail = pNewTail;
}

Queue::~Queue() {
	if (pHead != nullptr) {
		QueueNode* temp = pHead;
		while(temp->getNext() != nullptr) {
			pHead = temp->getNext();
			delete temp;
		}
	}
}


//member functions

void Queue::enqueue(Data& newData) {
	QueueNode* newNode = new QueueNode(newData);
	if (newNode != nullptr) {
		if (pHead == nullptr) {
			pHead = pTail = newNode;
		} else {
			pTail->setNext(newNode);
			pTail = newNode;
		}
	}
}

Data* Queue::dequeue() {
	QueueNode* temp = pHead;
	if (pHead == pTail) {
		Data data = *pHead->getData();
		pHead = pTail = nullptr;
		delete temp;
		return &data;
	} else {
		Data data = *pHead->getData();
		pHead = pHead->getNext();
		delete temp;
		return &data;
	}
}

void Queue::print() {
	QueueNode* temp = pHead;
	while (temp != nullptr) {
		std::cout << "Customer #" << temp->getData()->getCustomerNumber() << ", Service Time: " << temp->getData()->getServiceTime() << ", Total Time: " << temp->getData()->getTotalTime() << "\n";
		temp = temp->getNext();
	}
}

int Queue::getTotalTime(int self) { 
	if (pHead != nullptr) {
		QueueNode* temp = pHead;
		int totalTime = 0;
		while (temp->getNext() != nullptr) {
			totalTime = totalTime + temp->getData()->getServiceTime();
			temp = temp->getNext();
		}
		return totalTime+self;
	} else {
		return self;
	}
}

bool Queue::isEmpty() {
	bool returnVal = false;
	if (pHead == pTail && pHead == nullptr) {
		returnVal = true;
	}
	return returnVal;
}


//getters

QueueNode* Queue::getHead() {
	return pHead;
}

QueueNode* Queue::getTail() {
	return pTail;
}