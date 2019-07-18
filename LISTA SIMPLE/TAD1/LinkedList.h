// Created by felix on 4/3/2019.
#ifndef TAD1_LINKEDLIST_H
#define TAD1_LINKEDLIST_H

struct Node{
    int value;
    Node* next;

    Node(int value): value{value}, next{ nullptr}{}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList();
    ~LinkedList();

    //De acceso
    bool empty();
    int size();
    Node* getHead();
    Node* getTail();
    void print();

    //De Modificacion
    void add_head(int value);
    void add_tail(int value);
    void remove_head();
    void remove_tail();
    void insert(int bol);
};


#endif //TAD1_LINKEDLIST_H
