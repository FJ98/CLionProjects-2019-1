// Created by felix on 5/3/2019.
#ifndef REVISTAPOLIMORFISMO_LIBRO_H
#define REVISTAPOLIMORFISMO_LIBRO_H

#include "Volumen.h"

class Libro : public Volumen {
    int numLibros;
public:
    Libro();
    Libro(std::string nombre, int numLibros);
    void mostrar() override;
};


#endif //REVISTAPOLIMORFISMO_LIBRO_H
