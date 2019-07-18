// Created by felix on 4/30/2019.
#ifndef TAREA3RIVASLP_SIMULADOR_H
#define TAREA3RIVASLP_SIMULADOR_H

#include <vector>
#include <sstream>
#include "Carga.h"
#include <fstream>
#include <iterator>
#include <cmath>
#include <iostream>

class Simulador {
    int m_inter, n_inter;
    std::vector<Punto *> Punt;
    std::vector<Carga *> Carg;
public:
    Simulador();
    ~Simulador();
    Simulador(int h, int w);
    void SetPuntos(int h, int w);
    void LlenarPuntos();
    void LlenarCargas(std::string link);
    void Calcular();
    void Imprimir();
};


#endif //TAREA3RIVASLP_SIMULADOR_H
