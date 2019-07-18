#include <iostream>
#include "Geometria.h"
int main() {
    Punto p1(5,4,3);
    Punto p2(10,8,6);
    std::cout<<"Usando Clases"<<std::endl;
    std::cout<<"Punto a: "<<"("<<p1.getX()<<", "<<p1.getY()<<", "<<p1.getZ()<<")"<<std::endl;
    std::cout<<"Punto b: "<<"("<<p2.getX()<<", "<<p2.getY()<<", "<<p2.getZ()<<")"<<std::endl;
    std::cout<<"Distacia entre 2 puntos: "<<getDistance(p1, p2)<<std::endl;
    std::cout<<std::endl;

    //Usando struct
    Point ps1{};
    ps1.x=5;
    ps1.y=4;
    ps1.z=3;

    Point ps2{};
    ps2.x=10;
    ps2.y=8;
    ps2.z=6;
    std::cout<<"Usando Struct"<<std::endl;
    std::cout<<"Punto a: "<<"("<<ps1.x<<", "<<ps1.y<<", "<<ps1.z<<")"<<std::endl;
    std::cout<<"Punto b: "<<"("<<ps2.x<<", "<<ps2.y<<", "<<ps2.z<<")"<<std::endl;
    std::cout<<"Distacia entre 2 puntos: "<<getDistance(ps1, ps2)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Conclusion: Para este tipo de ejemplo es mejor usar struct porque el codigo es mucho mas corto."<<std::endl;

    return 0;
}