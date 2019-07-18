// Created by felix on 5/3/2019.
#ifndef AGREGACION_HERENCIA_LIBRO_H
#define AGREGACION_HERENCIA_LIBRO_H

#include "Volumen.h"
#include <string>
class Libro : public Volumen {
    int numLibros;
public:
    Libro(std::string p_nombre, int p_numVol, int p_numLibros);
    virtual void mostrar() override;
};


#endif //AGREGACION_HERENCIA_LIBRO_H
