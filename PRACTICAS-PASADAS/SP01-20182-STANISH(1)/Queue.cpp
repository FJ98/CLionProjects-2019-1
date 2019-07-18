// Created by felix on 5/5/2019.
#include "Queue.h"

Node::Node(Task *task, Node *next) : task{task}, next{next} {}
Queue::Queue():first{nullptr},last{nullptr} {}
Queue::~Queue() {first=nullptr; last=nullptr;}

void Queue::enqueue(Task *task) {
    Node* nuevo= new Node(task, nullptr);
    if(isEmpty()){
        first=nuevo;
        last=nuevo;
    }else{
        last->next=nuevo;
        last=nuevo;
    }
}

Task *Queue::dequeue() {
    Task* salida;
    Node* borrar;
    if(first!=nullptr){
        borrar=first;
        salida=first->task;
        first=first->next;
        delete borrar;
    }else{
        return nullptr;
    }
    return salida;
}

bool Queue::isEmpty() {
    return first== nullptr;
}
