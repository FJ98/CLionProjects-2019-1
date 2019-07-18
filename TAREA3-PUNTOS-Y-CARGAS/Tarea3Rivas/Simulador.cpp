// Created by felix on 4/24/2019.
#include "Simulador.h"
#include <iostream>
#include <vector>
#include <iomanip>
void Simulador::LlenarPuntos(int m, int n) {
    Punto pun;
    for(int fila=0;fila<m;fila++){
        for(int columna=0;columna<n;columna++){
            Puntos.push_back(pun);
        }
    }
    for (auto i: Puntos){
        for(auto j:Puntos) {
            std::cout << "(" << i.pos.x << ", " << j.pos.y << ") ";
        }
        std::cout<<std::endl;
    }
}

void Simulador::Calcular() {
    Carga car;
    //Potencial pot;
    double potencial;
    for(int i=0;i<Cargas.size();i++){
        potencial = (car.getPotencial().k*car.getPotencial().q)/car.getPotencial().r;
    }
    std::cout<<potencial<<std::endl;
    //potencial = (pot.k*pot.q)/pot.r;
}

void Simulador::LlenarCarga() {
    Carga car;
    for(int fila=0;fila<h;fila++){
        for(int columna=0;columna<w;columna++){
            Cargas.push_back(car);
        }
    }
}

void Simulador::Imprimir(){
    Carga c;
    for (int i=0; i<5;i++){
    std::cout<<"X: "<<c.getPosicion().x<<" ,Y: "<<c.getPosicion().y<<" ,V"<<std::endl;
    }
}

Simulador::Simulador(int m, int n) : h(m), w(n) {}
Simulador::Simulador(int h, int w, const std::vector<Punto> &Puntos, const std::vector<Carga> &Cargas) : h(h), w(w),
                                                                                                         Puntos(Puntos),
                                                                                                         Cargas(Cargas) {}
Simulador::Simulador() = default;
