// Created by felix on 5/29/2019.
#ifndef S2O3_ITLINKEDLIST_MYVECTOR_H
#define S2O3_ITLINKEDLIST_MYVECTOR_H


class MyVector {
    int* _arr;
    int _size;
public:
    MyVector() : _arr{nullptr}, _size{0} {}
    ~MyVector(){delete []_arr; _arr= nullptr;}
    void pushBack(int value);
    void insert(int pos, int& value);
    int getItem(int item);
    int size(){return _size;}
};


#endif //S2O3_ITLINKEDLIST_MYVECTOR_H
