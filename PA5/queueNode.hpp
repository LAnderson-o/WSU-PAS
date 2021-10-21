#ifndef NODE
#define NODE
#include "data.hpp"

class QueueNode{
public:
    //constructors
    QueueNode(Data& newData);
    ~QueueNode();

    //member functions
    void decrement();

    //getters
    Data* getData();
    QueueNode* getNext();

    //setters
    void setNext(QueueNode* newP);
    void setTotalTime(int newTime);
private:
    Data* pData;
    QueueNode* pNext;
};

#endif