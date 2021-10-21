#include "data.hpp"


//constructors

Data::Data() {
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}

Data::Data(int tCustomerNumber, int tServiceTime, int tTotalTime) {
	customerNumber = tCustomerNumber;
	serviceTime = tServiceTime;
	totalTime = tTotalTime;
}

Data::Data(Data& newData) {
	customerNumber = newData.getCustomerNumber();
	serviceTime = newData.getServiceTime();
	totalTime = newData.getTotalTime();
}


//getters

int Data::getCustomerNumber() {
	return customerNumber;
}

int Data::getServiceTime() {
	return serviceTime;
}

int Data::getTotalTime() {
	return totalTime;
}


//setters

void Data::setTotalTime(int newTime) {
	totalTime = newTime;
}

void Data::setServiceTime(int num) {
	serviceTime = num;
}
