// Created by felix on 4/30/2019.
#include "Carga.h"

Carga::Carga(int x, int y, float _q)  {PosX=x; PosY=y; q=_q;}
Carga::~Carga(){}

Punto::Punto(int x, int y) {PosX=x; PosY=y; Potencial=0.0;}
Punto::~Punto() {}
