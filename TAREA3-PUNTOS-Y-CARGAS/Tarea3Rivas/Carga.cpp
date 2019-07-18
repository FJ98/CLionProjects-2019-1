// Created by felix on 4/24/2019.
#include "Carga.h"

Carga::Carga() = default;
Posicion::Posicion() : x{0}, y{0} {}
Posicion::Posicion(int x, int y) : x{x}, y{y} {}

Potencial::Potencial() : k{0}, q{0}, r{0} {};
Punto::Punto() = default;
Punto::Punto(Posicion pos, Potencial pot): pos{pos},pot{pot} {}

Potencial Carga::getPotencial() {
    return poten;
}

Posicion Carga::getPosicion() {
    return posi;
}
