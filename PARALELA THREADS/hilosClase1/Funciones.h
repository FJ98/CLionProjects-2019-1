// Created by felix on 6/19/2019.
#ifndef HILOSCLASE1_FUNCIONES_H
#define HILOSCLASE1_FUNCIONES_H

#include <iostream>
#include <numeric>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>
static const int NUM_HILOS = 2;

// 4) Implementar una función que realice el ordenamiento merge utilizando threads.
template <class Iter>
void doMerge(int sup, Iter first, Iter last) {
    Iter middle;
    for (int i = 0; i < sup; ++i) {
        if(last - first > 1){
            middle = first + (last - first) / 2;
            doMerge(sup, first, middle);
            doMerge(sup, middle, last);
            std::inplace_merge(first,middle,last);
        }
    }

}

template <typename T>
std::vector<T> mergeSort(std::vector<T> data) {
    int param = 0;
    int paso = (data.size()/NUM_HILOS);
    std::vector<std::thread> hilos;
    for (int i = 0; i < NUM_HILOS; ++i) {
        int temp = param;
        param += paso;
        hilos.emplace_back(&doMerge<std::vector<int>::iterator>, temp, data.begin(), data.end() );
        param++;
    }
    for (int j = 0; j < NUM_HILOS; ++j) {
        hilos[j].join();
    }
    return data;
}
//--------------------------------------------------------------------------------------------------

// 2) Similar al caso anterior desarrollar una función que dado
// un valor, elimine todos los valores iguales al valor dado.
template <typename T>
void eliminalo(int idHilo, std::vector<T> & vector, T & value){
    int inf, sup, extra;
    extra = vector.size() % NUM_HILOS;
    inf = idHilo * (vector.size() / NUM_HILOS);
    sup = (idHilo + 1) * (vector.size() / NUM_HILOS);
    if (idHilo == NUM_HILOS - 1 && extra != 0) { sup += extra; }

    for (int i = inf; i < sup; ++i) {
        vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());
    }
}

template <typename T>
auto eliminar(std::vector<T> vector, T value){
    std::vector<std::thread> hilos;
    for (int i = 0; i < NUM_HILOS; ++i) {
        hilos.emplace_back(&eliminalo<T>, i, std::ref(vector), std::ref(value));
    }
    for (int j = 0; j < NUM_HILOS; ++j) {
        hilos[j].join();
    }
    return vector;
}
//---------------------------------------------------------------------------------------------------

// 1) Función que ejecute la suma de los valores (enteros o float) de un vector y que utilizando 2
//thread realice la suma total del vector.
template <typename T>
void sumVec(int idHilo, std::vector<T> & vector, T & suma){
    int inf, sup, extra;
    extra = vector.size() % NUM_HILOS;
    inf = idHilo * (vector.size() / NUM_HILOS);
    sup = (idHilo + 1) * (vector.size() / NUM_HILOS);

    if (idHilo == NUM_HILOS - 1 && extra != 0) { sup += extra; }

    for (int i = inf; i < sup; ++i) {
        suma += vector[i];
    }
}

template <typename T>
T sumar(std::vector<T> & vector){
    T suma{0}; std::vector<std::thread> hilos;

    for (int i = 0; i < NUM_HILOS; ++i) {
        hilos.emplace_back(&sumVec<T>, i, std::ref(vector), std::ref(suma));
    }
    for (int j = 0; j < NUM_HILOS; ++j) {
        hilos[j].join();
    }
    return suma;
}


#endif //HILOSCLASE1_FUNCIONES_H
