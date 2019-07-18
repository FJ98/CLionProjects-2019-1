// Created by felix on 5/3/2019.
#ifndef AGREGACION_HERENCIA_REVISTA_H
#define AGREGACION_HERENCIA_REVISTA_H

#include "Volumen.h"

class Revista : public Volumen{
    int numRevistas;
public:
    Revista(std::string p_nombre, int p_numVol, int p_numRevistas);
    virtual void mostrar() override;
};


#endif //AGREGACION_HERENCIA_REVISTA_H
