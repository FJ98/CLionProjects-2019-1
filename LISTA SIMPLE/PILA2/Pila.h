// Created by felix on 4/10/2019.
#ifndef PILA2_PILA_H
#define PILA2_PILA_H

struct Posicion{
    int x;
    int y;
    Posicion(int _x, int _y);
    Posicion();
};
enum Color{RED, YELLOW, BLUE, BLACK};

struct Punto{
    Posicion pos;
    Color col;
    Punto* next;
    Punto* prev;
    Punto(Posicion _pos, Color _col);
    Punto();
};

class Pila {
    Punto* top;
    int size;
public:
    Pila();
    void Destroy();
    void Push(Punto _punto);
    Punto Pop();
    Punto Peek();
    int Size();
    bool IsEmpty();
    Punto* GetTop();
};
void Print(Pila* pil);
void Agrupar(Pila* original, Pila* red, Pila* yellow, Pila* blue, Pila* black);


#endif //PILA2_PILA_H
