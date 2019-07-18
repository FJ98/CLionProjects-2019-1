// Created by felix on 5/3/2019.
#include "Funciones.h"

void rellenar(Biblioteca* Bib1){
    Volumen* rev1 = new Revista("ojo",5);
    Volumen* rev2 = new Revista("hola",10);
    Volumen* lib1 = new Libro("Mate_1",20);
    Volumen* lib2 = new Libro("C++",2);
    Bib1->incluir(rev1);
    Bib1->incluir(rev2);
    Bib1->incluir(lib1);
    Bib1->incluir(lib2);
    Bib1->mostrarBiblioteca();
}

void crear(){
    auto Bib1 = new Biblioteca();
    rellenar(Bib1);
    delete Bib1;
}