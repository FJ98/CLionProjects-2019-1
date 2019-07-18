// Created by felix on 5/3/2019.
#include "Libro.h"
#include <iostream>
void Libro::mostrar() {
    std::cout<<"Volumen #"<<numVol<<"\t\t\tNumero del Libro: "<<numLibros<<"\t\tTitulo: "<<nombre<<std::endl;
}

Libro::Libro(std::string p_nombre, int p_numVol, int p_numLibros) : Volumen{p_nombre,p_numVol}, numLibros{p_numLibros} {}
