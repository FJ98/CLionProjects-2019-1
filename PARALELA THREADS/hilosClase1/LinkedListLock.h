// Created by felix on 6/24/2019.
#ifndef HILOSCLASE1_LINKEDLISTLOCK_H
#define HILOSCLASE1_LINKEDLISTLOCK_H

#include <iostream>
#include <thread>
#include <mutex>
#include <future>
static constexpr int N_HILOS = 2;
// 3) Desarrollar una estructura Linked List que permita insertar mas de un valor concurrente.
class LinkedListLock{
private:
    struct Node{
        int val;
        Node* next;
        //std::mutex mutex;
        explicit Node (int val) : val{val}, next{nullptr} {}
    };
    Node* head;
    Node* tail;
    int tam;
public:
    explicit LinkedListLock() : tail{nullptr}, head{nullptr}, tam{0} {}

    void pushBack(int val){
        auto nuevoNodo = new Node(val);
        if (this->head == nullptr) {
            this->head = nuevoNodo;
        }else{ tail->next = nuevoNodo; }
        this->tail = nuevoNodo;
        this->tam++;
    }

    void pushFront(int data){
        Node *temporal = new Node(data);
        if(tam>0){
            temporal->next = head;
            head = temporal;
        }
        else{
            head = temporal;
            tail = temporal;
        }
        tam++;
    }

    void pop_front(){
        Node *remover = head;
        head = head->next; //head = remover->next;
        delete remover;
        tam--;
    }

    void pop_back(){
        Node *remover = head;
        while(remover->next!=tail){
            remover = remover->next;
        }
        tail = remover;
        delete remover->next;
        tail->next = nullptr;
        tam--;
    }
    int size(){ return tam; }

    void insertConHilosMAL(int idHilo, int & val, int & pos, LinkedListLock & lst) {
        int pos_actual = 0;
        int inf, sup, extra;
        extra = lst.size() % N_HILOS;
        inf = idHilo * (lst.size() / N_HILOS);
        sup = (idHilo + 1) * (lst.size() / N_HILOS);
        if (idHilo == N_HILOS - 1 && extra != 0) { sup += extra; }

        for (int i = inf; i < sup; ++i) {
            if (pos == 0) { lst.pushFront(val); }
            else if (pos == lst.tam) { lst.pushBack(val); }
            else {
                pos_actual++;
                Node *buscar = lst.head;
                while (pos_actual != pos) {
                    buscar = buscar->next;
                    pos_actual++;
                }
                Node *nuevo = new Node(val);
                nuevo->next = buscar->next;
                buscar->next = nuevo;
                tam++;
            }
        }
    }

    void insert(int val, int pos) {
        int pos_actual = 0;
        if (pos == 0) { pushFront(val); }
        else if (pos == tam) { pushBack(val); }
        else {
            pos_actual++;
            Node *buscar = head;
            while (pos_actual != pos) {
                buscar = buscar->next;
                pos_actual++;
            }
            Node *nuevo = new Node(val);
            nuevo->next = buscar->next;
            buscar->next = nuevo;
            tam++;
        }
    }

    void insertConHilos(int val, int pos, LinkedListLock list) {
        int pos_actual = 0;
        if (pos == 0) { list.pushFront(val); }
        else if (pos == list.tam) { list.pushBack(val); }
        else {
            pos_actual++;
            Node *buscar = list.head;
            while (pos_actual != pos) {
                buscar = buscar->next;
                pos_actual++;
            }
            Node *nuevo = new Node(val);
            nuevo->next = buscar->next;
            buscar->next = nuevo;
            tam++;
        }
    }
    LinkedListLock testInsertConHilos(int &ins, int &pos){
        auto fun = &LinkedListLock::insertConHilos;
        std::thread t1(fun, this, ins, pos, *this);
        //std::thread t2(fun, this, ins + 1, pos + 1, *this);
        t1.join();
        //t2.join();
        return *this;
    }

    LinkedListLock testInsert2ConHilos(int &ins1, int &pos1, int &ins2, int &pos2){
        auto fun = &LinkedListLock::insertConHilos;
        std::thread t1(fun, this, ins1, pos1, *this);
        std::thread t2(fun, this, ins2, pos2, *this);
        t1.join(); t2.join();
        return *this;
    }

    void print(){
        Node *buscar = head;
        int actual = 0;
        do{
            std::cout<< buscar->val <<"  ";
            buscar=buscar->next;
            actual++;
        } while(actual!=tam); std::cout << std::endl;
    }
};



#endif //HILOSCLASE1_LINKEDLISTLOCK_H
