#include <iostream>
#include "Simulador.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Simulador s1;
    s1.LlenarPuntos(5,3);
    s1.LlenarCarga();
    s1.Calcular();
    s1.Imprimir();
    return 0;
}