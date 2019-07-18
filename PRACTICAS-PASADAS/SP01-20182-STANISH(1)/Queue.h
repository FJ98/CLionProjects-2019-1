// Created by felix on 5/5/2019.
#ifndef SP01_20182_STANISH_1__QUEUE_H
#define SP01_20182_STANISH_1__QUEUE_H

#include "Task.h"

struct Node{
    Node* next;
    Task* task;
    Node(Task* task, Node* next);
};

class Queue {
    Node* first;
    Node* last;
public:
    Queue();
    void enqueue(Task* task);
    Task* dequeue();
    bool isEmpty();
    ~Queue();
};


#endif //SP01_20182_STANISH_1__QUEUE_H
