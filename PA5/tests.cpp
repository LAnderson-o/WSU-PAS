#include "tests.hpp"

bool Tests::emptyEnqueue(Data newData) {
	bool returnVal = false;
	Queue testQueue;
	if (testQueue.getHead() == testQueue.getTail()) {
		if (testQueue.getHead() == nullptr) {
			//std::cout << "Queue is empty\n";
			//testQueue.print();
			testQueue.enqueue(newData);
			if (testQueue.getHead() == testQueue.getTail() && testQueue.getHead() != nullptr) {
				//std::cout << "Queue has one element\n";
				//testQueue.print();
				Data* queueData = testQueue.getHead()->getData();
				if (queueData->getCustomerNumber() == newData.getCustomerNumber()) {
					//std::cout << "Queue Data: " << queueData->getCustomerNumber() << " = Passed Data: " << newData.getCustomerNumber() << "\n";
				}
				if (queueData->getServiceTime() == newData.getServiceTime()) {
					//std::cout << "Queue Data: " << queueData->getServiceTime() << " = Passed Data: " << newData.getServiceTime() << "\n";
				}
				if (queueData->getTotalTime() == newData.getTotalTime()) {
					//std::cout << "Queue Data: " << queueData->getTotalTime() << " = Passed Data: " << newData.getTotalTime() << "\n";
				}

				if (queueData->getCustomerNumber() == newData.getCustomerNumber() && queueData->getServiceTime() == newData.getServiceTime() && queueData->getTotalTime() == newData.getTotalTime()) {
					returnVal = true;
				}
			} else {
				//std::cout << "Queue is irregular\n";
				//testQueue.print();
				return returnVal;
			}
		}
	}
	return returnVal;
}

bool Tests::singleEnqueue(Data newData) {
	bool returnVal = false;
	Queue testQueue;
	Data testData(0, 0, 0);
	testQueue.enqueue(testData);
	if (testQueue.getHead() == testQueue.getTail()) {
		if (testQueue.getHead() != nullptr) {
			//std::cout << "Queue has one element\n";
			//testQueue.print();
			testQueue.enqueue(newData);
			if (testQueue.getHead() != testQueue.getTail()) {
				//std::cout << "Queue has more than one element\n";
				//testQueue.print();
				returnVal = true;
			}
		}
	}
	testQueue.dequeue();//woo
	testQueue.dequeue();
	return returnVal;
}

bool Tests::singleDequeue() {
	bool returnVal = false;
	Queue testQueue;
	Data testData(0, 0, 0);
	testQueue.enqueue(testData);
	testQueue.dequeue();
	if (testQueue.getHead() == testQueue.getTail() && testQueue.getHead() == nullptr) {
		returnVal = true;
	}
	return returnVal;
}

bool Tests::doubleDequeue() {
	bool returnVal = false;
	Queue testQueue;
	Data testData0(0, 0, 0);
	Data testData1(1, 1, 1);
	testQueue.enqueue(testData0);
	testQueue.enqueue(testData1);
	testQueue.dequeue();
	testQueue.dequeue();
	if (testQueue.getHead() == testQueue.getTail() && testQueue.getHead() == nullptr) {
		returnVal = true;
	}
	return returnVal;
}

void  Tests::runSim24() {
	int n = 0; //minutes
	int eArival = 0; //express arrival time
	int nArival = 0; //normal arrival time
	int customerNum = 0;
	Queue express;
	Queue normal;

	while (n < 1440) {


		//Arrival
		if (eArival == 0) {// ecustomer arrives
			eArival = rand() % 5 + 1; // set new arrival time
			int tempServiceTime = rand() % 5 + 1; // generate customer service time
			Data newECustomer(++customerNum, tempServiceTime, express.getTotalTime(tempServiceTime)); // generate customer data
			express.enqueue(newECustomer);// customer gets in line
			std::cout << "customer #" << newECustomer.getCustomerNumber() << " entered express line @ " << n << " minutes\n";
		}

		if (nArival == 0) {
			nArival = rand() % 8 + 3;
			int tempServiceTime = rand() % 8 + 3;
			Data newNCustomer(++customerNum, tempServiceTime, normal.getTotalTime(tempServiceTime));
			normal.enqueue(newNCustomer);
			std::cout << "customer #" << newNCustomer.getCustomerNumber() << " entered normal line @ " << n << " minutes\n";
		}


		//Service sim
		if (express.getHead() != nullptr) {// check if there are customers in line
			if (express.getHead()->getData()->getServiceTime() == 0) {
				Data* tempCustomer = express.dequeue(); // customer is done
				std::cout << "customer #" << tempCustomer->getCustomerNumber() << " was in express line for " << tempCustomer->getTotalTime() << " minutes\n";
			}
			else {
				express.getHead()->decrement(); // customer is still being processed
			}
		}

		if (normal.getHead() != nullptr) {
			if (normal.getHead()->getData()->getServiceTime() == 0) {
				Data* tempCustomer = normal.dequeue();
				std::cout << "customer #" << tempCustomer->getCustomerNumber() << " was in normal line for " << tempCustomer->getTotalTime() << " minutes\n";
			}
			else {
				normal.getHead()->decrement();
			}
		}


		//print
		if (n % 10 == 0 && n != 0) {
			std::cout << "\n\nExpress:\n";
			express.print();
			std::cout << "\nNormal:\n";
			normal.print();
			std::cout << "\n\n";
		}

		++n, --eArival, --nArival; // time
	}
}

void Tests::runSim(int length) {
	int n = 0; //minutes
	int eArival = 0; //express arrival time
	int nArival = 0; //normal arrival time
	int customerNum = 0;
	Queue express;
	Queue normal;

	while (n < length) {


		//Arrival
		if (eArival == 0) {// ecustomer arrives
			eArival = rand() % 5 + 1; // set new arrival time
			int tempServiceTime = rand() % 5 + 1; // generate customer service time
			Data newECustomer(++customerNum, tempServiceTime, express.getTotalTime(tempServiceTime)); // generate customer data
			express.enqueue(newECustomer);// customer gets in line
			std::cout << "customer #" << newECustomer.getCustomerNumber() << " entered express line @ " << n << " minutes\n";
		}

		if (nArival == 0) {
			nArival = rand() % 8 + 3;
			int tempServiceTime = rand() % 8 + 3;
			Data newNCustomer(++customerNum, tempServiceTime, normal.getTotalTime(tempServiceTime));
			normal.enqueue(newNCustomer);
			std::cout << "customer #" << newNCustomer.getCustomerNumber() << " entered normal line @ " << n << " minutes\n";
		}


		//Service sim
		if (express.getHead() != nullptr) {// check if there are customers in line
			if (express.getHead()->getData()->getServiceTime() == 0) {
				Data* tempCustomer = express.dequeue(); // customer is done
				std::cout << "customer #" << tempCustomer->getCustomerNumber() << " was in express line for " << tempCustomer->getTotalTime() << " minutes\n";
			}
			else {
				express.getHead()->decrement(); // customer is still being processed
			}
		}

		if (normal.getHead() != nullptr) {
			if (normal.getHead()->getData()->getServiceTime() == 0) {
				Data* tempCustomer = normal.dequeue();
				std::cout << "customer #" << tempCustomer->getCustomerNumber() << " was in normal line for " << tempCustomer->getTotalTime() << " minutes\n";
			}
			else {
				normal.getHead()->decrement();
			}
		}


		//print
		if (n % 10 == 0 && n != 0) {
			std::cout << "\n\nExpress:\n";
			express.print();
			std::cout << "\nNormal:\n";
			normal.print();
			std::cout << "\n\n";
		}

		++n, --eArival, --nArival; // time
	}
}

bool Tests::runTests() {
	bool returnVal = false;
	Tests test;
	Data testData(3, 2, 1);

	std::cout << "Empty Enqueue  ... ";
	bool EE = test.emptyEnqueue(testData);
	if (EE == true) {
		std::cout << "passed\n";
	} else {
		std::cout << "not passed\n";
	}
	
	std::cout << "Single Enqueue ... ";
	bool SE = test.singleEnqueue(testData);
	if (SE == true) {
		std::cout << "passed\n";
	}
	else {
		std::cout << "not passed\n";
	}

	std::cout << "Single Dequeue ... ";
	bool SD = test.singleDequeue();
	if (SD == true) {
		std::cout << "passed\n";
	}
	else {
		std::cout << "not passed\n";
	}

	std::cout << "Double Dequeue ... ";
	bool DD = test.doubleDequeue();
	if (DD == true) {
		std::cout << "passed\n";
	}
	else {
		std::cout << "not passed\n";
	}

	if (EE == true && SE == true && SD == true && DD == true) {
		returnVal = true;
		std::cout << "All tests passed !\n";
	}

	return returnVal;
}