// Created by felix on 5/3/2019.
#ifndef REVISTAPOLIMORFISMO_VOLUMEN_H
#define REVISTAPOLIMORFISMO_VOLUMEN_H

#include <string>
class Volumen {
protected:
    std::string nombre;
    int numVol;
public:
    void set_numVol(int num);
    Volumen();
    Volumen(std::string &nombre);

    virtual void mostrar()=0;
};


#endif //REVISTAPOLIMORFISMO_VOLUMEN_H
