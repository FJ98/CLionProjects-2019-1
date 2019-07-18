// Created by felix on 5/15/2019.
#ifndef INC_2_SESION_FUNCIONES_H
#define INC_2_SESION_FUNCIONES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <random>

template <typename T>
void print (T arg) {
    std::cout<<arg;
}

template <typename T, typename... Params>
void print (T first_arg,Params... args) {
    print(first_arg);
    std::cout << ' ';
    print(args...);
}

template <typename T>
auto suma (T num) {
    return num;
}

template <typename T, typename... Params>
auto suma (T first_arg, Params... args) {
    auto sum = suma(first_arg) + suma(args...);
    return sum;
}

template <typename T>
auto comparar (T dato) {
    if (dato) {
        return false;
    }
}

template <typename T>
auto comparar (T dato1, T dato2) {
    return dato1 == dato2;
}

template <typename T, typename... Params>
auto comparar (T first_arg, T second_arg,Params... args) {

    comparar(first_arg);
    comparar(first_arg, second_arg);
    comparar(args...);

    return !(comparar(first_arg) == comparar(first_arg, second_arg) && comparar(first_arg) == comparar(args...) &&
             comparar(first_arg, second_arg) == comparar(args...));
}


template <typename T>
T sum_product (T dato) {return dato;}

template <typename T>
T sum_product (T dato1, T dato2) {

    if(dato1 == dato2){
        auto prod = sum_product(dato1) * sum_product(dato2);
        return prod;
    }else{
        return false;
    }
}

template <typename T, typename... Params>
T sum_product (T first_arg, T second_arg, Params... args) {

    sum_product(first_arg);
    sum_product(first_arg, second_arg);
    sum_product(args...);

    auto tot_sum = sum_product(first_arg, second_arg) + sum_product(args...);
    return tot_sum;

}


template <unsigned int n>
struct factorial{
    enum {value = n * factorial <n-1>::value};
};

template <>
struct factorial<0>{
    enum {value = 1};
};

template <typename T, typename U, typename... Params>
T swaps(T first_arg, Params... args){

}

//---------------------------------------------------------------------
template <class T>
T partition(T arr[], int start, int end){
    T valorPivot = arr[start];
    int posPivot = start;
    for (int pos = start + 1; pos <= end; pos++){
        if (arr[pos] < valorPivot){
            std::swap(arr[posPivot + 1], arr[pos]);
            std::swap(arr[posPivot], arr[posPivot + 1]);
            posPivot ++;
        }
    }
    return posPivot;
}

template <class T>
T quickSort(T arr[], int start, int end){
    if (start < end) {
        T p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
    return *arr;
}

template <class T>
T partition(std::vector<T> vec[], int start, int end){
    T valorPivot = vec[start];
    int posPivot = start;
    for (int pos = start + 1; pos <= end; pos++){
        if (vec[pos] < valorPivot){
            std::swap(vec[posPivot + 1], vec[pos]);
            std::swap(vec[posPivot], vec[posPivot + 1]);
            posPivot ++;
        }
    }
    return posPivot;
}

template <class T>
T quickSort(std::vector<T> vec [], int start, int end){
    if (start < end) {
        T p = partition(vec, start, end);
        quickSort(vec, start, p - 1);
        quickSort(vec, p + 1, end);
    }
    return vec;
}
//-----------------------------------------------------
template <typename T>
auto alternar(T s1, T s2, T s3){
    while (!s1.empty() || !s2.empty()) {
        s3.push(s1.top());
        s3.push(s2.top());
        s1.pop();
        s2.pop();
    }
    return s3;
}



//-----------------------------------------------------

#endif //INC_2_SESION_FUNCIONES_H
