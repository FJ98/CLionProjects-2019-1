// Created by felix on 5/3/2019.
#ifndef REVISTAPOLIMORFISMO_BIBLIOTECA_H
#define REVISTAPOLIMORFISMO_BIBLIOTECA_H

#include <vector>
#include "Volumen.h"
#include "Revista.h"
#include "Libro.h"

class Biblioteca {
private:
    int maxLibros;
    int maxRevistas;
    std::vector<Volumen*> Vol;
public:
    Biblioteca();
    void mostrarBiblioteca();
    void incluir(Volumen *entrada_v);
};


#endif //REVISTAPOLIMORFISMO_BIBLIOTECA_H
