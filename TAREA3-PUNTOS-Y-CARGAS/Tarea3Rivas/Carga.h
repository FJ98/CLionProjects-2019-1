// Created by felix on 4/24/2019.
#ifndef TAREA3RIVAS_CARGA_H
#define TAREA3RIVAS_CARGA_H

struct Posicion{
    int x;
    int y;
    Posicion();
    Posicion(int x, int y);
};
struct Potencial{
    double q;
    double k;
    double r;
    Potencial();
};
struct Punto{
    Posicion pos;
    Potencial pot;
    Punto();
    Punto(Posicion pos, Potencial pot);
};

class Carga {
private:
    Posicion posi;
    Potencial poten;
public:
    Carga();
    Potencial getPotencial();
    Posicion getPosicion();
};


#endif //TAREA3RIVAS_CARGA_H
