#include <iostream>
#include "Pila.h"
#include <random>
int main() {
    std::random_device rand;
    Pila *pil=new Pila;
    Pila *red = new Pila; Pila *yellow = new Pila;
    Pila *blue = new Pila; Pila *black = new Pila;
    Posicion pos1; Color c1; Punto p1;

    std::cout<<"Pil Original: "<<std::endl;
    int cant = 10;
    for (int i = 0; i < cant; i++) {
        pos1 = Posicion(rand () % 601, rand () % 601);
        c1 = Color (rand () % 4);
        p1 = Punto(pos1,c1);
        pil->Push(p1);
    }
    //pil->Print();
    Print(pil);

    std::cout<<"Tamano actual de la Pila: "<<pil->Size()<<std::endl;
    std::cout<<"PEEK: [Posicion: ("<<pil->Peek().pos.x<<", "<<pil->Peek().pos.y<<") - Color: "<<pil->Peek().col<<"]"<<std::endl;
    std::cout<<"POP: [Posicion: ("<<pil->Pop().pos.x<<", "<<pil->Pop().pos.y<<") - Color: "<<pil->Pop().col<<"]"<<std::endl;
    std::cout<<"PEEK: [Posicion: ("<<pil->Peek().pos.x<<", "<<pil->Peek().pos.y<<") - Color: "<<pil->Peek().col<<"]"<<std::endl;
    std::cout<<"Tamano actual de la Pila: "<<pil->Size()<<std::endl<<std::endl;

    Agrupar(pil, red, yellow, blue, black);



    std::cout<<"Pil Red: "<<std::endl;
    //red->Print();
    Print(red);

    std::cout<<"Pil Yellow: "<<std::endl;
    //yellow->Print();
    Print(yellow);

    std::cout<<"Pil Blue: "<<std::endl;
    //blue->Print();
    Print(blue);

    std::cout<<"Pil Black: "<<std::endl;
    //black->Print();
    Print(black);

    pil->Destroy();
    red->Destroy();
    yellow->Destroy();
    blue->Destroy();
    black->Destroy();

    //std::cout<<red->Size()<<std::endl; por que no imprime una vez que llamo a Destroy?

    return 0;
}