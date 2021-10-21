#ifndef DATA
#define DATA

#include <iostream>


class Data {
public:
    //constructors
    Data();
    Data(int tCustomerNumber, int tServiceTime, int tTotalTime);
    Data(Data& newData);

    //getters
    int getCustomerNumber();
    int getServiceTime();
    int getTotalTime();

    //setters
    void setTotalTime(int newTime);;
    void setServiceTime(int num);

private:
    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
};

#endif