#ifndef PRIMERACLASE_GEOMETRIA_H
#define PRIMERACLASE_GEOMETRIA_H

#include <math.h>

class Punto{
    int x;
    int y;
    int z;
public:
    Punto(int x, int y, int z);
    int getX();
    int getY();
    int getZ();
};
double getDistance(Punto a, Punto b); // Con class

// Con struct
struct Point{
    int x{};
    int y{};
    int z{};
};
double getDistance(Point a, Point b); // Con struct

#endif //PRIMERACLASE_GEOMETRIA_H
