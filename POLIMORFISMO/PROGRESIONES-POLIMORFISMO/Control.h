// Created by felix on 5/8/2019.
#ifndef PROGRESIONES_POLIMORFISMO_CONTROL_H
#define PROGRESIONES_POLIMORFISMO_CONTROL_H

#include "Progresion.h"

class Control{
    std::vector<Progresion*> Prog;
    Progresion* p;
    int datos;
    int cantidad;
    std::vector<long> data;
public:
    void pushdata(int data);
    void imprimirSuma();
    void imprimirProg();
};



#endif //PROGRESIONES_POLIMORFISMO_CONTROL_H
