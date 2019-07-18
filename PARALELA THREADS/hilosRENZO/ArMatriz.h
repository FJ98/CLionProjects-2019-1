// Created by felix on 6/20/2019.
#ifndef HILOSRENZO_ARMATRIZ_H
#define HILOSRENZO_ARMATRIZ_H

#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <assert.h>
#include <sys/time.h>
#include <random>

template <typename Class>
void MultiplicacionParcial(int Param1, int Param2, int Param3, Class m1, Class m2, Class m3) {
    for(int i = 0; i < Param1; i++) {
        for (int j = 0; j < Param2; j++) {
            for (int k = 0; k < Param3; k++) {
                m1.get_m()[i][j] += m2.get_m()[i][k] * m3.get_m()[k][j];
            }
        }
    }
}

class Matriz_Concurrente {
    int numHilos = 2;
    int filas;
    int columnas;
    int** m;
    friend Matriz_Concurrente operator* (const Matriz_Concurrente &m_1, const Matriz_Concurrente &m_2);
public:

    Matriz_Concurrente(int filas, int columnas): filas{filas}, columnas{columnas} {
        m = new int*[filas];
        for (int i = 0; i < filas; i++) {
            m[i] = new int[columnas];
        }
    }
    Matriz_Concurrente() {
        for (int i = 0; i < filas; ++i)
            delete [] m[i];
        delete [] m;
    }

    int** get_m() { return m; }

    void fillWith0() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                m[i][j] = 0;
            }
        }
    };

    void printMatries () {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void fill_matriz() {
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                m[i][j] = rand()%15;
    }

};

Matriz_Concurrente operator* (const Matriz_Concurrente &m_1, const Matriz_Concurrente &m_2) {
    Matriz_Concurrente _m(m_1.filas, m_2.columnas);
    _m.fillWith0();

    std::vector <std::thread> h3;

    int param = 0;
    int paso = (m_1.filas/m_1.numHilos);
    for (int i = 0; i < m_1.numHilos; i++) {
        int temp = param;
        param += paso;
        h3.emplace_back(MultiplicacionParcial<Matriz_Concurrente>, temp, _m.columnas, _m.columnas, std::ref(_m), std::ref(m_1), std::ref(m_2));
        param++;
    }

    for (int i = 0; i < m_1.numHilos; i++) {
        h3[i].join();
    }
    return _m;
}


template <typename T1>
class Matriz{
    int filas=0;
    int columnas=0;
    std::vector<std::vector<T1>> matriz;
public:
    Matriz(){};
    Matriz(int filas, int columnas, std::vector<std::vector<T1>> matriz):filas(filas),columnas(columnas),matriz(matriz){};
    int Filas(){return filas;};
    int Columnas(){return columnas;};
    void RellanrMatriz(int filas, int columnas);
    std::vector<std::vector<T1>> GetMatriz(){ return matriz;};
    void PrintMatriz() {
        for (int i=0; i<filas; i++) {
            for (int j = 0; j < columnas; j++) {
                std::cout<<matriz[i][j]<<"  ";
            }
            std::cout<<'\n';
        }
        std::cout<<'\n';
    };
    Matriz operator*(Matriz b){
        std::vector<std::vector<T1>> bm=b.GetMatriz();
        std::vector<std::vector<T1>> rm;
        std::vector<T1> fila;
        T1 multi=0;
        for(int i=0;i<filas;i++){
            fila.clear();
            for(int j=0;j<b.Columnas();j++){
                multi=0;
                for(int k=0;k<columnas;k++){
                    multi+=matriz[i][k]*bm[k][j];
                }
                fila.push_back(multi);
            }
            rm.push_back(fila);
        }
        Matriz resultado(filas,b.Columnas(),rm);
        return resultado;
    }
};
std::random_device r;

template <>
void Matriz<int>::RellanrMatriz(int filas, int columnas){
    Matriz::filas=filas;
    Matriz::columnas=columnas;
    std::vector<int> fila;
    for (int i=0; i<Matriz::filas; i++) {
        fila.clear();
        for (int j = 0; j < Matriz::columnas; j++) {
            fila.push_back(r()%100+1);
        }
        matriz.push_back(fila);
    }
}

template <>
void Matriz<double>::RellanrMatriz(int filas, int columnas){
    Matriz::filas=filas;
    Matriz::columnas=columnas;
    std::vector<double> fila;
    for (int i=0; i<Matriz::filas; i++) {
        fila.clear();
        for (int j = 0; j < Matriz::columnas; j++) {
            fila.push_back((r()%100+1)*1.0/(r()%5+1));
        }
        matriz.push_back(fila);
    }
}


#endif //HILOSRENZO_ARMATRIZ_H
