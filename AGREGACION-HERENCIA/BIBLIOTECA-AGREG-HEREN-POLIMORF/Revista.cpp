// Created by felix on 5/3/2019.
#include "Revista.h"
#include <iostream>
void Revista::mostrar() {
    std::cout<<"Volumen #"<<numVol<<"\t\tNumero de la Revista: "<<numRevistas<<"\t\tTitulo: "<<nombre<<std::endl;
}

Revista::Revista(std::string p_nombre, int p_numVol,int p_numRevistas) : Volumen(p_nombre, p_numVol), numRevistas(p_numRevistas) {}


