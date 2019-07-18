// Created by felix on 5/8/2019.
#include "Control.h"

void Control::imprimirSuma() {
    std::cout<<p->calcular(data,cantidad)<<std::endl;
}

void Control::imprimirProg() {
    for (auto item: Prog) {
        std::cout<<item<<" ";
    }
}