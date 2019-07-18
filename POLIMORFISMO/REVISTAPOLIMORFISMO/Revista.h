// Created by felix on 5/3/2019.
#ifndef REVISTAPOLIMORFISMO_REVISTA_H
#define REVISTAPOLIMORFISMO_REVISTA_H

#include "Volumen.h"

class Revista : public Volumen{
    int numRevistas;
public:
    Revista(std::string nombre, int numRevistas);
    void mostrar() override;
    //Revista();
};


#endif //REVISTAPOLIMORFISMO_REVISTA_H
