#include <iostream>
#include "Simulador.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    const std::string LINK = "cargas.csv";

    auto sim = new Simulador(6,5);

    sim->LlenarPuntos();
    sim->LlenarCargas(LINK);

    std::cout<<std::endl;
    sim->Imprimir();

    sim->Calcular();


    delete sim;

    return 0;
}