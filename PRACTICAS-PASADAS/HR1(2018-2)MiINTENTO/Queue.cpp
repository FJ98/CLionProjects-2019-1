// Created by felix on 3/31/2019.
#include "Queue.h"

Node::Node(Task *task, Node *next) {
    this->task=task; //Por que inicializar de esta manera? (De esto me olvide y no imprimia en consola)
    this->next=next; //Por que inicializar de esta manera? (De esto me olvide y no imprimia en consola)
}
Queue::Queue() {}

void Queue::enqueue(Task *task) {
    if (last == nullptr)
    {
        Node* p = new Node(task, nullptr);
        first=p;
        last=p;
    }else{
        Node* p = new Node(task, nullptr);
        last->next=p;
        last=p;
    }
}
Task *Queue::dequeue() {
    Task* output;
    Node* borrar;
    if(first != nullptr){
        borrar = first;
        output = first -> task;
        first = first -> next;
        delete borrar;
    }
    else{
        return nullptr;
    }
    return output;
}
bool Queue::isEmpty() {
    return first== nullptr;
}

Queue::~Queue() {}
