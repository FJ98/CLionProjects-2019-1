// Created by felix on 4/4/2019.
#ifndef TAD2_LISTA_H
#define TAD2_LISTA_H

struct Nodo{
    int value;
    Nodo* next;
    explicit Nodo(int _value);
};

class Lista {
private:
    Nodo* head;
    Nodo* tail;
public:
    Lista();
    ~Lista();

    bool empty();
    int size();
    Nodo* getHead();
    Nodo* getTail();

    void add_head(int value);
    void add_tail(int value);
    void remove_head();
    void remove_tail();
    void insert(int pos, int value);

};


#endif //TAD2_LISTA_H
