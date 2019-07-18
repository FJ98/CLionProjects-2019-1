// Created by felix on 5/3/2019.
#ifndef AGREGACION_HERENCIA_BIBLIOTECA_H
#define AGREGACION_HERENCIA_BIBLIOTECA_H

#include "Volumen.h"
#include "Revista.h"
#include "Libro.h"
#include <vector>

class Biblioteca {
    int maxLibros;
    int maxRevistas;
    std::vector<Volumen*> Vol;
public:
    Biblioteca();
    Biblioteca(int p_maxRev, int p_maxLib);
    void mostrarBiblioteca();
    void incluir(Volumen* entrada_v);
};


#endif //AGREGACION_HERENCIA_BIBLIOTECA_H
