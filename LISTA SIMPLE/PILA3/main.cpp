#include <iostream>
#include <random>
#include "Pila.h"
int main() {
    std::random_device rand;
    std::cout << "Hello, World!" << std::endl;
    Pila* pil = new Pila;
    int cantPush=10;
    int cantPop=4;

    for(int i=0;i<cantPush;i++){
        pil->push(rand()%20);
    }
    pil->print();
    std::cout<<"PEEK: "<<pil->Peek()->dato<<std::endl;
    std::cout<<"Size actual: "<<pil->Size()<<std::endl<<std::endl;

    for(int i=0; i<cantPop;i++){
        pil->pop();
    }
    pil->print();
    std::cout<<"PEEK: "<<pil->Peek()->dato<<std::endl;
    std::cout<<"Size actual: "<<pil->Size()<<std::endl<<std::endl;

    return 0;
}
