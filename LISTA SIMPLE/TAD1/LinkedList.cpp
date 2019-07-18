// Created by felix on 4/3/2019.
#include "LinkedList.h"
#include <iostream>
bool LinkedList::empty() {
    return (head==nullptr and tail==nullptr);
}

int LinkedList::size(){
    int count=0;
    if(empty()){return 0;}
    Node* actual = head;
    /*
    while(head->next != nullptr){
        count++;
        actual=actual->next;
    }*/
    do{
        count++;
        actual=actual->next;
    }while (actual!= nullptr);
    return count;
}

Node* LinkedList::getHead(){
    return head;
}

Node* LinkedList::getTail(){
    return tail;
}

void LinkedList::print(){
    //std::cout<<getHead()->value;
    std::cout<<getTail()->value;

}

void LinkedList::add_head(int value) {
    Node* temp = new Node(value);

    if (empty()){
        tail=temp;
        head=temp;
    } else{
        temp->next=head;
        head=temp;
    }
}

void LinkedList::add_tail(int value) {
    Node* temp = new Node(value);

    if (empty()){
        tail=temp;
        head=temp;
    }else{
        //temp->next=tail;
        tail->next=temp;
        tail=temp;
    }
}

void LinkedList::remove_head() {
    Node* temp = nullptr;
    temp=head;
    head=head->next;
    delete temp;
}

void LinkedList::remove_tail() {
    Node* temp = nullptr;
    temp=tail;
    tail=tail->next;
    delete temp;
}

void LinkedList::insert(int bol) {

}

LinkedList::~LinkedList() {
    //Generalizar este destructor
    Node* temp = nullptr;
    for (int i = 0; i < size(); ++i) {
        temp=head;
        head=head->next;
        delete temp;

        temp=tail;
        delete temp;
    }

}

LinkedList::LinkedList(): head{nullptr}, tail{nullptr}{}

