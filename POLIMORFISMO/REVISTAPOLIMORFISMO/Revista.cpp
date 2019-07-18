// Created by felix on 5/3/2019.
#include "Revista.h"
#include <iostream>
void Revista::mostrar() {
    std::cout<<"Volumen: "<<numVol<<"\t\tRevista: "<<numRevistas<<"\t\tTitulo: "<<nombre<<std::endl;
}

Revista::Revista(std::string nombre, int numRevistas) : Volumen{nombre}, numRevistas{numRevistas} {}



//Revista::Revista() : Volumen(nombre),numRevistas{0} {}