#ifndef QUEUE
#define QUEUE
#include "queueNode.hpp"

class Queue{
public:
    //constructors
    Queue(QueueNode* pNewHead = nullptr, QueueNode* pNewTail = nullptr);
    ~Queue();

    //member functions
    void enqueue(Data& newData);
    Data* dequeue();
    void print();
    bool isEmpty();

    //getters
    QueueNode* getHead();
    QueueNode* getTail();
    int getTotalTime(int self);

private:
    QueueNode* pHead;
    QueueNode* pTail;
};

#endif