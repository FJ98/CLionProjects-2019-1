// Created by felix on 5/29/2019.
#ifndef S2O3_ITLINKEDLIST_LINKEDLIST_H
#define S2O3_ITLINKEDLIST_LINKEDLIST_H

struct Node{
    int value;
    Node* next;
};

class LinkedListIterator{
    Node* node;
    explicit LinkedListIterator(Node* node) : node{node}{}
    friend class LinkedList;

public:
    int& operator*(){return node->value;}
    bool operator==(const LinkedListIterator& rightSide){
        return node == rightSide.node;
    }
    bool operator!=(const LinkedListIterator& rightSide){
        return node != rightSide.node;
    }
    LinkedListIterator operator++(){
        node=node->next;
        return *this;
    }
    const LinkedListIterator operator++(int){
        auto it = *this;
        ++*this;
        return it;
    }
};

class LinkedList {
    Node* head_;
    Node* tail_;
    int size_;
public:
    LinkedList(): head_{nullptr}, tail_{nullptr}, size_{0} {}

    ~LinkedList() {
        Node* next;
        for (Node* p = head_; p != nullptr; p = next) {
            next = p->next;
            delete p;
        }
    }
    int size() const { return size_; }
    void push_back(int value) {
        Node* temp = new Node{value, nullptr};
        if (tail_ != nullptr)
            tail_->next = temp;
        else
            head_ = temp;
        tail_ = temp;
        size_++;
    }
    using iterator = LinkedListIterator;

    iterator begin(){return iterator{head_};}
    iterator end(){return iterator{nullptr};}
};


#endif //S2O3_ITLINKEDLIST_LINKEDLIST_H
