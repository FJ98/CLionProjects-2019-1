// Created by felix on 6/20/2019.
#ifndef HILOSRENZO_EJMATRIZRIVAS_H
#define HILOSRENZO_EJMATRIZRIVAS_H

#include <random>
#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;

mutex mtx;

template <typename T, size_t size>
class MatrizR {
    size_t n = size;
    T** m = nullptr;
public:
    void generar_matriz() {
        m = new T*[n];
        for (auto i = 0; i < n; i++)
            m[i] = new T[n];

        random_device rd;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < n; j++)
                m[i][j] = static_cast<T>(rd()%10);
    }

    void mostrar_matriz() {
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++)
                cout << setw(3) << m[i][j];
            cout << '\n';
        }
    }

    T sumar_fila(size_t fila) {
        return accumulate(m[fila], m[fila]+n, 0);
    }

    void sumar_fila_matrices_1(MatrizR<T, size>& m1, MatrizR<T, size>& m2,
                               size_t fila, promise<T> prm) {
        prm.set_value(m1.sumar_fila(fila) + m2.sumar_fila(fila));
    }

    void ejecuta_threads(MatrizR<T, size>& m2) {
        vector<thread> hilos(n); vector<promise<T>> promises(n);
        vector<future<T>> futures(n);
        auto pos = 0;
        auto prm = begin(promises);
        auto ftr = begin(futures);
        for (auto& h: hilos) {
            *ftr = prm->get_future();
            h = thread(&MatrizR<T, size>::sumar_fila_matrices_1, this,
                       ref(*this), ref(m2), pos, move(*prm));
            pos++;
            prm++;
            ftr++;
        }
        vector<T> vt;
        for (auto& futr: futures) {
            vt.emplace_back(futr.get());
        }
        for (auto& item: vt)
            cout << setw(5) << item;
        cout << '\n';
        for (auto& h: hilos)
            h.join();
    }

    T sumar_fila_matrices_2(MatrizR<T, size>& m1, MatrizR<T, size>& m2, size_t fila) {
        return m1.sumar_fila(fila) + m2.sumar_fila(fila);
    }

    void ejecuta_async(MatrizR<T, size>& m2) {
        vector<future<T>> futures(n);
        auto pos = 0;
        for (auto& ftr: futures) {
            ftr = async(&MatrizR::sumar_fila_matrices_2, this,
                        ref(*this), ref(m2), pos);
            pos++;
        }
        vector<T> vt;
        for (auto& ftr: futures) {
            vt.emplace_back(ftr.get());
        }
        for (auto& item: vt)
            cout << setw(5) << item;
        cout << '\n';
    }
};

#endif //HILOSRENZO_EJMATRIZRIVAS_H
