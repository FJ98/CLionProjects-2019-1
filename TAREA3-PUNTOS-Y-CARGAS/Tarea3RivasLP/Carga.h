// Created by felix on 4/30/2019.
#ifndef TAREA3RIVASLP_CARGA_H
#define TAREA3RIVASLP_CARGA_H

class Carga {
public:
    int PosX, PosY;
    float q;
    const float k = 8.99;
    Carga(int x, int y, float _q);
    ~Carga();
};

class Punto{
public:
    int PosX, PosY;
    float Potencial;
    Punto(int x, int y);
    ~Punto();
};


#endif //TAREA3RIVASLP_CARGA_H
