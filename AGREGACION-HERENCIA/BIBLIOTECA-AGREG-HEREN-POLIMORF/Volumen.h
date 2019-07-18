// Created by felix on 5/3/2019.
#ifndef AGREGACION_HERENCIA_VOLUMEN_H
#define AGREGACION_HERENCIA_VOLUMEN_H

#include <string>

class Volumen {
protected:
    std::string nombre;
    int numVol;
public:
    Volumen(std::string p_nombre, int numVol);
    virtual void mostrar()=0;
    //void set_numVol(int p_numVol);
    int getnumVol();
};


#endif //AGREGACION_HERENCIA_VOLUMEN_H
