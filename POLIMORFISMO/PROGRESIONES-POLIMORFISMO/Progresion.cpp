// Created by felix on 5/7/2019.
#include "Progresion.h"
#include <iostream>
#include <cmath>
Progresion::Progresion():first{1},cur{1} {}
long Progresion::firstValue() {return first;}

Progresion::Progresion(long p_first): first{p_first}, cur{p_first} {}

AritProg::AritProg(long p_first,int p_inc):inc{p_inc}, Progresion{p_first} {}
long AritProg::nextValue() {return cur=cur+inc;}

long AritProg::calcular(std::vector<long>p_v1, int cantidad) {
    long suma=0;
    for (auto item: p_v1) {
        suma=((first+item)*cantidad)/2;
    }
    return suma;
}

std::vector<long> AritProg::generarProgresion( int cantidad) {
    std::vector<long> v1;
    for (int i = 0; i < cantidad; ++i) {
        v1.push_back((first+(i)*inc));
    }
    return v1;
}


GeoProg::GeoProg(long p_first, int p_base) {
    this->first = p_first;
    this->base = p_base;
}

long GeoProg::nextValue() {
    return cur *= base;
}

long GeoProg::calcular(std::vector<long>p_v1, int cantidad) {
    long suma=0;
    for (auto item: p_v1) {
        suma=((first+item)*cantidad)/2;
    }
    return suma;
}

std::vector<long> GeoProg::generarProgresion( int cantidad) {
    std::vector<long> p_v1;
    // p_v1.reserve(cantidad);
for (int i = 0; i < cantidad; ++i) {
        p_v1.push_back(first* static_cast<long>(pow(base,i)));
    }
    return p_v1;
}

void imprimirProgresion(std::vector<long> v2) {
    for(auto item: v2){
        std::cout<<item<<" ";
    }std::cout<<std::endl;
}
void imprimirSuma(long suma){std::cout<<suma<<std::endl;}

