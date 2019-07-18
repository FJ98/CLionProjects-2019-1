#include <iostream>
#include "Progresion.cpp"
#include "Control.cpp"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Progresion* p = new AritProg(5,3);
    std::vector<long> v2;

    v2 = p->generarProgresion(4);
    long suma = p->calcular(v2,4);
    imprimirProgresion(v2);
    imprimirSuma(suma);

    Progresion* pg = new GeoProg(2,3);
    std::vector<long> vg2;

    vg2 = pg->generarProgresion(4);
    long sumag = pg->calcular(vg2,4);
    imprimirProgresion(vg2);
    imprimirSuma(sumag);

    /*
      p->generarProgresion(4);
      p->calcular(v2,4);
      p->imprimirProgresion();
      p->imprimirSuma();

    */


    return 0;
}