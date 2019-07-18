#include <iostream>
#include "Biblioteca.h"
/* Duda: Como puedo hacer una vez que la biblio recibe un maximo de libros te detenga y
 * te diga maximo de libros alcanzados o maximo de revistas alcanzado o ambos y que ahi pare de lo que se haya alcanzado el maximo.
 * Duda: Como contar todos los elementos de la biblioteca.
 * Duda: Como contar todas las revistas.
 * Duda: Como contar todos los libros.
 * */
int main() {
    auto Bib1 = new Biblioteca(5,5);
    Volumen* rev1 = new Revista("Hola", 1, 3);
    Volumen* rev2 = new Revista("Somos", 7, 5);
    Volumen* lib1 = new Libro("C++ Prime", 3, 7);
    Volumen* lib2 = new Libro("Arqui", 4, 9);
    Volumen* lib3 = new Libro("Mucho Ruido", 5, 9);
    Volumen* lib4 = new Libro("Arboles", 9, 3);
    Volumen* lib5 = new Libro("Curioso", 7, 1);
    Volumen* lib6 = new Libro("Perro", 5, 2);
    Volumen* lib7 = new Libro("Oso", 9, 4);
    Bib1->incluir(rev1);
    Bib1->incluir(rev2);
    Bib1->incluir(lib1);
    Bib1->incluir(lib2);
    Bib1->incluir(lib3);
    Bib1->incluir(lib4);
    Bib1->incluir(lib5);
    Bib1->incluir(lib6);
    Bib1->incluir(lib7);

    Bib1->mostrarBiblioteca();

    delete Bib1;
    return 0;
}