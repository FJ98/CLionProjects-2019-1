// Created by felix on 5/2/2019.
#ifndef T3_LP_SIMULADOR_H
#define T3_LP_SIMULADOR_H

#include "Carga.h"
#include "Puntos.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <cmath>
#include <iostream>

class Simulador {
private:
    int m_inter,n_inter;
    std::vector<Puntos *> Punt;
    std::vector<Carga *> Carg;

public:
    Simulador(int h, int w);
    Simulador();
    ~Simulador();
    void SetPuntos(int h, int w);
    void LLenarPuntos();
    void LLenarCargas(std::string link);
    void Imprimir();
    void Calcular();
};


#endif //T3_LP_SIMULADOR_H
