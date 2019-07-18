//
// Created by felix on 5/2/2019.
//

#ifndef T3_LP_CARGA_H
#define T3_LP_CARGA_H


class Carga
{
public:
    int PosX,PosY;
    const float k = 8.99;
    float q;
public:
    Carga(int x, int y, float _q);
    ~Carga();

};


#endif //T3_LP_CARGA_H
