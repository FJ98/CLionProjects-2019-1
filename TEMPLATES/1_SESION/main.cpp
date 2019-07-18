#include <iostream>
#include "string"
#include "Semana7.h"
#include "Arreglo.h"
int main() {
    std::cout << "Max(1, 2): " << UTEC::max(1, 2) << std::endl;
    std::cout << "Max(1, 2): " << UTEC::max(3, 2.225) << std::endl;
    std::cout << "Max<int, double, int>(1, 2.5): " << UTEC::max<int, double, int>(1, 2.5) << std::endl;
    std::cout << "Max('H', 'h'): " << UTEC::max('H', 'h') << std::endl;
    std::cout << "Max(Hola, hola): " << UTEC::max("Hola", "hola") << std::endl;

    Arreglo<double> ad;
    Arreglo<int> ae;

    return 0;
}