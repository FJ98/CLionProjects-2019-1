// Created by felix on 5/3/2019.
#include "Biblioteca.h"
#include <iostream>
void Biblioteca::mostrarBiblioteca() {
    for(auto item: Vol){
        item->mostrar();
    }
}

void Biblioteca::incluir(Volumen *entrada_v) {
    Vol.push_back(entrada_v);
    //if(entrada_v->getnumVol()==maxRevistas){}maxLibros++;
}

Biblioteca::Biblioteca(int p_maxRev, int p_maxLib) : maxRevistas{p_maxRev}, maxLibros{p_maxLib} {}
Biblioteca::Biblioteca():maxRevistas{0},maxLibros{0} {}
