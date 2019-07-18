// Created by felix on 5/3/2019.
#include "Libro.h"
#include <iostream>
void Libro::mostrar() {
    std::cout<<"Volumen: "<<numVol<<"\t\tLibro: "<<numLibros<<"\t\tTitulo: "<<nombre<<std::endl;
}

Libro::Libro() : numLibros(0){}

Libro::Libro(std::string nombre, int numLibros): Volumen{nombre}, numLibros{numLibros} {

}

