// Created by felix on 4/24/2019.
#ifndef TAREA3RIVAS_SIMULADOR_H
#define TAREA3RIVAS_SIMULADOR_H

#include "Carga.h"
#include <vector>

class Simulador {
private:
    int h;
    int w;
    std::vector<Punto> Puntos;
    std::vector<Carga> Cargas;
public:
    Simulador();
    Simulador(int m, int n);
    Simulador(int h, int w, const std::vector<Punto> &Puntos, const std::vector<Carga> &Cargas);

    void LlenarPuntos(int m, int n);
    void LlenarCarga();
    void Calcular();
    void Imprimir();
};


#endif //TAREA3RIVAS_SIMULADOR_H
