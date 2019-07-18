// Created by felix on 3/31/2019.
#ifndef HR1_2018_2_MIINTENTO_QUEUE_H
#define HR1_2018_2_MIINTENTO_QUEUE_H

#include "Task.h"
struct Node{
    Node* next;
    Task* task;
    Node(Task* task, Node* next);
};

class Queue {
private:
    Node* first;
    Node* last;
public:
    Queue();
    void enqueue(Task* task);
    Task* dequeue();
    bool isEmpty();
    ~Queue();
};


#endif //HR1_2018_2_MIINTENTO_QUEUE_H
