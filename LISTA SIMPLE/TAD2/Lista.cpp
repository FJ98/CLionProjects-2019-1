// Created by felix on 4/4/2019.
#include "Lista.h"
#include <iostream>
Nodo::Nodo(int _value): value(value), next(nullptr){}

Lista::Lista() : head(nullptr), tail(nullptr){}
Lista::~Lista(){}

bool Lista::empty(){
    return head== nullptr && tail== nullptr;
}

int Lista::size(){
    int count=0;
    Nodo* temp=head;
    do{
        count++;
        temp=temp->next;
    }while(temp!= nullptr);
    return count;
}

Nodo* Lista::getHead(){return head;}
Nodo* Lista::getTail(){return tail;}

void Lista::add_head(int value){
    Nodo* temp = new Nodo(value);
    if (size()==0){
        head=temp;
        tail=temp;
    }else{
        temp->next=head;
        head=temp;
    }
}

void Lista::add_tail(int value){
    Nodo* temp = new Nodo(value);
    if (empty()){
        head=temp;
        tail=temp;
    }else{
        tail->next=temp;
        tail=temp;
    }
}

void Lista::remove_head(){
    Nodo* temp = head;
    head=head->next;
    delete temp;
}

void Lista::remove_tail(){
    Nodo* temp = head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    tail=temp;
    delete temp->next   ;
    if(tail->next== nullptr){
        std::cout<<"Chicho"<<std::endl;
    }else{
        std::cout<<"Wuibu"<<std::endl;
    }
}

void Lista::insert(int pos, int value){

}
