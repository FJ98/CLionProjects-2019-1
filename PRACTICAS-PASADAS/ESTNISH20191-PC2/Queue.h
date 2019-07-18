// Created by felix on 5/14/2019.
#ifndef ESTNISH20191_PC2_QUEUE_H
#define ESTNISH20191_PC2_QUEUE_H

#include "Process.h"

template <typename T>
struct Node{
    T *data;
    Node<T> *next;
    Node() : data{nullptr}, next{nullptr} {}
    explicit Node(T *p_data) : data{p_data}{}
};


template <typename T>
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int tMax;
    int actual;
public:
    Queue() : head{nullptr}, tail{nullptr}, tMax{11}, actual{0} {}
    void enqueue(T *p_data);
    Process* dequeue();
    bool isEmpty() {return head == nullptr;}
    bool isFull() {return actual==tMax;}
};

template<typename T>
void Queue<T>::enqueue(T *p_data) {
    auto nuevoNodo = new Node<T>(p_data);
    if (isEmpty()){
        head = nuevoNodo;
        tail = nuevoNodo;
    }
    else if (isFull()){
        tail->next = nullptr;
        std::cout << "El tamano maximo Queue es 11 no se puede anadir mas de 11 elementos al Queue." << std::endl;
        std::cout << "Usted esta anadiendo 12, eso es ilegal." << std::endl;
        std::cout << "Solo se anadiran los 11 primeros elementos que haya anadido." << std::endl;
        std::cout << "A continuacion,  se imprimira los 11 primeros elementos anadio: \n" << std::endl;
    }
    else{
        tail->next=nuevoNodo;
        tail=nuevoNodo;
    }
    actual++;
}

template<typename T>
Process* Queue<T>::dequeue() {
    Process* salida;
    Node<T> * borrar;
    if (!isEmpty()) {
        borrar=head;
        salida=*(head->data);
        head = head->next;
        delete borrar;
        actual--;
    }
    else{return nullptr;}

    return salida;
}


#endif //ESTNISH20191_PC2_QUEUE_H
