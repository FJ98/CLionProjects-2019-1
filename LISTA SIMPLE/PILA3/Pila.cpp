#include "Pila.h"
#include <iostream>
Nodo::Nodo(int dato) : dato(dato), prev(nullptr), next(nullptr){}
Nodo::Nodo() = default;

Pila::Pila() :top(nullptr), size(0) {}
void Pila::push(int value){
    Nodo* nuevo = new Nodo(value);
    if(IsEmpty()){
        top=nuevo;
    }else{
        top->next=nuevo;
        nuevo->prev=top;
        top=nuevo;
    }
    size++;
}
Nodo Pila::pop(){
    Nodo* nuevo=top;
    Nodo retornar = *nuevo;
    top=nuevo->prev;
    delete nuevo;
    size--;
    return retornar;
}
bool Pila::IsEmpty(){return top== nullptr;}
int Pila::Size(){return size;}
Nodo* Pila::Peek(){
    Nodo* nuevo = top;
    return nuevo;
}
Nodo* Pila::GetTop(){return top;}
void Pila::print(){
    Nodo* nod = top;
    while(nod!= nullptr){
        std::cout<<nod->dato<<std::endl;
        nod=nod->prev;
    }
    std::cout<<std::endl;
}
