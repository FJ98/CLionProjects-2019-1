#include "Simulador.h"

int main(){
    const std::string LINK = "cargas.csv";

    auto sim = new Simulador(6,5);

    sim->LLenarPuntos();
    sim->LLenarCargas(LINK);
    sim->Calcular();

    delete sim;

    return 0;
}