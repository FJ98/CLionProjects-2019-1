/*
// Created by felix on 6/21/2019.
#ifndef HILOSRENZO_SMATRIZ_H
#define HILOSRENZO_SMATRIZ_H

#include <thread>
#include <iostream>
#include <random>

static const int NUM_HILS = 4;

using namespace std;

template <class T>
class MatrizAsincrona;
template <class T>
void multiplicar(unsigned int lim_inf, unsigned int lim_sup, MatrizAsincrona<T>& matrizAsincrona1, MatrizAsincrona<T>& matrizAsincrona2, MatrizAsincrona<T>& matrizAsincrona3);

template <class T>
class MatrizAsincrona {
    int filas;
    int columnas;
public:
    friend void multiplicar(unsigned int, unsigned int, MatrizAsincrona<T>&, MatrizAsincrona<T>&, MatrizAsincrona<T>&);
    T** matriz;
    MatrizAsincrona(int filas, int columnas):filas{filas}, columnas{columnas} {
        matriz = new T* [filas]();
        for (int i = 0; i < columnas; ++i) {
            matriz[i] = new T [columnas]();
        }
    }
    MatrizAsincrona(int filas, int columnas, random_device rd):filas{filas}, columnas{columnas} {
        matriz = new T* [filas];
        for (int i = 0; i < columnas; ++i) {
            matriz[i] = new T [columnas];
        }
        for (int j = 0; j < filas; ++j) {
            for (int i = 0; i < columnas; ++i) {
                matriz[j][i] = (rd()%5)+1;
            }
        }
    }

    auto operator*(MatrizAsincrona& m) {
        if (columnas == m.get_filas()) {
            MatrizAsincrona matrizAsincrona(filas, m.get_columnas());
            vector<thread> hilos;
//            void (*pm) (unsigned int, unsigned int, MatrizAsincrona<T>&, MatrizAsincrona<T>&, MatrizAsincrona<T>&) = &MatrizAsincrona::multiplicar;
            unsigned int lim_inf, lim_sup;
            for (int i = 0; i < NUM_HILS; ++i) {
                lim_inf = i*(filas/NUM_HILS);
                lim_sup = (i+1)*(filas/NUM_HILS);
                hilos.emplace_back(multiplicar<T>, lim_inf, lim_sup, ref(matriz), ref(m), ref(matrizAsincrona));
            }
            for (int i = 0; i < NUM_HILS; ++i) {
                hilos[i].join();
            }
        } else {
            cout << "No se pueden multiplicar las matrices." << endl;
        }
    }
    unsigned int get_filas() { return filas; }
    unsigned int get_columnas() { return columnas; }
    void print() {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }


};

template <class T>
void multiplicar(unsigned int lim_inf, unsigned int lim_sup, MatrizAsincrona<T>& matrizAsincrona1, MatrizAsincrona<T>& matrizAsincrona2, MatrizAsincrona<T>& matrizAsincrona3) {
    T r;
    for (int i = lim_inf; i < lim_sup; ++i) {
        for (int j = 0; j < matrizAsincrona1.get_columnas(); ++j) {
            r = matrizAsincrona1.matriz[i][j];
            for (int k = 0; k < matrizAsincrona2.get_columnas(); ++k) {
                matrizAsincrona3[i][k] += r*matrizAsincrona2[j][k];
            }
        }
    }
}


#endif //HILOSRENZO_SMATRIZ_H
*/
