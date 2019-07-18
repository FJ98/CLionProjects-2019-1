// Created by felix on 5/3/2019.
#include "Biblioteca.h"

void Biblioteca::mostrarBiblioteca() {
    for (auto & it_vol : Vol) {
        it_vol->mostrar();
    }
}

void Biblioteca::incluir(Volumen *entrada_v) {
    Vol.push_back(entrada_v);
    entrada_v->set_numVol(Vol.size());
    //entrada_v->get_numVol();
}

Biblioteca::Biblioteca() : maxLibros{0},maxRevistas{0} {}
