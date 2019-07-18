// Created by ruben on 4/5/19.
#include "LinkedList.h"

UTEC::LinkedList::LinkedList() {

}

UTEC::LinkedList::~LinkedList() {

}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = position;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return position == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {
    return position;
}

UTEC::Node *UTEC::LinkedList::get_tail() {
    return head;
}

void UTEC::LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        head = temp;
        position = temp;
    } else {
        temp->next = position;
        position = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        head = temp;
        position = temp;
    } else {
        head->next = temp;
        head = temp;
    }
}

void UTEC::LinkedList::print() {
    //Completar
}

void UTEC::LinkedList::insert(Node* position, const Location& data){
    //Completar
    Node *newNode = new Node(data);
    Node *aux1 = position;
    Node *aux2 = head;
    while((aux1 != nullptr)){
        aux2=aux1;
        aux1=aux1->next;
    }
    if(position==aux1){
        position=newNode;
    }
    else{
        aux2->next=newNode;
    }
    newNode->next=aux1;
}

UTEC::Node *UTEC::LinkedList::search(std::string position_id) {
    //Completar
    return nullptr;
}


UTEC::Node::Node(const Location &data) : data(data), next(nullptr) {}
