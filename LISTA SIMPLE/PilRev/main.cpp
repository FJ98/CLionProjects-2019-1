#include <iostream>
#include <random>

using std::cout;
using std::cin;
using std::endl;

enum Colores{RED,YELLOW,BLUE,BLACK};

struct Puntos{
    int pos_x;
    int pos_y;

    Puntos(int x,int y): pos_x(x),pos_y(y) {};
    Puntos(){};
};

struct Posicion{

    Puntos punt;
    Colores  color;
    Posicion *next;
    Posicion *prev;

    Posicion(Puntos punt, Colores color): punt(punt),color(color), next(nullptr), prev(nullptr){};

    Posicion(){};
};

class Pila{

    Posicion *Top;
    int size;

public:

    Pila(): Top(nullptr),size(0){};

    Posicion *GetTop(){return Top;}

    void push(Puntos pun, Colores color){

        Posicion *nuevo = new Posicion(pun,color);
        if(size == 0){
            Top = nuevo;
        }
        else{
            Top->next = nuevo;
            nuevo->prev = Top;
            Top = nuevo;
        }
        size++;
    }

    bool IsEmpty() {return Top == nullptr;}

    int Size(){return size;}

    Posicion Pop(){
        Posicion *actual = Top;
        Posicion retornar(Top->punt,Top->color);
        Top = Top->prev;
        size--;
        delete actual;
        return retornar;

    }

    void print(){
        Posicion *buscar = Top;
        while(buscar!= nullptr){
            cout<<buscar->punt.pos_x<<" - "<<buscar->punt.pos_y<<" - "<<buscar->color<<std::endl;
            buscar = buscar->prev;
        }
    }

    Posicion Peek(){
        Posicion  retornar(Top->punt,Top->color);
        return retornar;
    }

    void Destroy(){
        Posicion *actual = Top;
        do{
            Top = Top->prev;
            delete actual;
            actual = Top;
            size--;
        }while(Top!= nullptr);

    }


};

void Agrupar(Pila *original, Pila *Red, Pila *Yellow, Pila *Blue, Pila *Black){
    Posicion *actual = original->GetTop();
    while(actual!= nullptr){
        switch(actual->color){
            case 0: Red->push(actual->punt,actual->color); break;
            case 1: Yellow->push(actual->punt,actual->color); break;
            case 2: Blue->push(actual->punt,actual->color); break;
            case 3: Black->push(actual->punt,actual->color); break;
        }
        actual = actual->prev;
    }

}

int main() {


    Pila *pila = new Pila();
    Pila *Red = new Pila();
    Pila *Yellow = new Pila();
    Pila *Blue = new Pila();
    Pila *Black = new Pila();
    Posicion p;
    Puntos puntitos;

    std::random_device rand;

    //cout<<pila->IsEmpty()<<" - "<<pila->Size()<<endl;

    for(int i=0;i<25;i++){
        puntitos = Puntos(rand()%601,rand()%601);
        pila->push(puntitos,Colores(rand()%4));
    }

    pila->print();


    Agrupar(pila,Red,Yellow,Blue,Black);

    cout<<"Solo rojos"<<endl<<endl;
    Red->print();

    cout<<"Solo Yellow"<<endl<<endl;
    Yellow->print();

    cout<<"Solo Blue "<<endl<<endl;
    Blue->print();

    cout<<"Solo Black "<<endl<<endl;
    Black->print();

    cout<<pila->IsEmpty()<<" - "<<pila->Size()<<endl;


    p = pila->Peek();

    cout<<"\nPEEK"<<p.punt.pos_x<<" - "<<p.punt.pos_y<<" - "<<p.color<<endl<<endl;

    pila->print();


    p = pila->Pop();

    cout<<"\nPOP"<<p.punt.pos_x<<" - "<<p.punt.pos_y<<" - "<<p.color<<endl<<endl;

    pila->print();

    cout<<"\nPEEK"<<p.punt.pos_x<<" - "<<p.punt.pos_y<<" - "<<p.color<<endl<<endl;

    pila->Destroy();
    Red->Destroy();
    Blue->Destroy();
    Yellow->Destroy();
    Black->Destroy();

    delete pila;

    return 0;
}