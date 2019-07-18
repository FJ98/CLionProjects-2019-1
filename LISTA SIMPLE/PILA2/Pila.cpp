// Created by felix on 4/10/2019.
#include "Pila.h"
#include <iostream>

Posicion::Posicion(int _x, int _y) : x(_x), y(_y) {}
Posicion::Posicion() = default;

Punto::Punto(Posicion _pos, Color _col) : pos(_pos), col(_col), next(nullptr), prev(nullptr){}
Punto::Punto() = default;

Pila::Pila(): top(nullptr), size(0){}

void Pila::Destroy(){
    // Se libera la memoria. Se establece el número de elementos a cero y la referencia a top a nulo.
    Punto *borrar = top;
    while(borrar!=nullptr){
        borrar=borrar->prev;
        delete borrar;
        //borrar=top;
        size--;
    }
}
void Pila::Push(Punto _punto){
    //Agrega un punto en el top de la pila y actualiza la referencia a top.
    auto *nue = new Punto(_punto);
    if(IsEmpty()){
        top=nue; // cual es la dieferencia con nue=top?
    }else{
        top->next=nue;
        nue->prev=top;
        top=nue;
    }
    size++;
}
Punto Pila::Pop(){
    // Retorna el punto en el top, eliminarlo de la pila y actualizar la referencia al top.
    Punto *nue = top;
    Punto ret(top->pos,top->col);//Que diferencia hay con Punto retornar(nuevo->pos,nuevo->col);
    top = top->prev; // cual es la dieferencia con nuevo->prev=top? con esto actualizas la referencia?
    size--;
    delete nue;//Con esto lo borras?
    return ret;
}
Punto Pila::Peek(){
    // Retorna el punto en el top, NO eliminarlo de la pila, NI actualizar la referencia a top.
    //Punto *nue=top;
    Punto ret(top->pos,top->col);
    return ret;
}
int Pila::Size(){return size;}
bool Pila::IsEmpty(){return top == nullptr;}
Punto* Pila::GetTop(){return top;}
/*
void Pila::Print() {
    Punto *most = top;
    while(most!= nullptr){
        std::cout<<"Posicion: ("<<most->pos.x<<", "<<most->pos.y<<") - Color: "<<most->col<<std::endl;
        most=most->prev;
    }
    std::cout<<std::endl;
}*/

void Print(Pila* pil) {
    Punto *most = pil->GetTop();
    while(most!= nullptr){
        std::cout<<"Posicion: ("<<most->pos.x<<", "<<most->pos.y<<") - Color: "<<most->col<<std::endl;
        most=most->prev;
    }
    std::cout<<std::endl;
}

void Agrupar(Pila* original, Pila* red, Pila* yellow, Pila* blue, Pila* black){
    Punto* act = original->GetTop();
    Punto p1;
    while(act!= nullptr){
        p1 = Punto(act->pos, act->col);
        switch (act->col){
            case 0: red->Push(p1); break;
            case 1: yellow->Push(p1); break;
            case 2: blue->Push(p1); break;
            case 3: black->Push(p1); break;
        }
        act=act->prev;
    }
}

