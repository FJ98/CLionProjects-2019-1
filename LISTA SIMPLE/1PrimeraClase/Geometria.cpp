#include "Geometria.h"

// Con class
Punto::Punto(int x, int y, int z) : x(x), y(y), z(z) {}

int Punto::getX()
{
    return x;
}
int Punto::getY()
{
    return y;
}
int Punto::getZ()
{
    return z;
}
double getDistance(Punto a, Punto b)
{
    double distance{0};
    distance=sqrt(((a.getX()-b.getX())*(a.getX()-b.getX()))+((a.getY()-b.getY())*(a.getY()-b.getY()))+((a.getZ()-b.getZ())*(a.getZ()-b.getZ())));
    return distance;
}

// Con Struct
double getDistance(Point a, Point b)
{
    double distance{0};
    distance=sqrt( ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y)) + ((a.z-b.z)*(a.z-b.z)) );
    return distance;
}