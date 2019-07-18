// Created by felix on 5/7/2019.
#ifndef PROGRESIONES_POLIMORFISMO_PROGRESION_H
#define PROGRESIONES_POLIMORFISMO_PROGRESION_H

#include <vector>

class Progresion {
protected:
    long first;
    long cur;
public:
    Progresion();
    explicit Progresion(long p_first);
    long firstValue();
    virtual long nextValue() = 0;
    virtual long calcular(std::vector<long>p_v1, int cantidad) = 0;
    virtual std::vector<long> generarProgresion(int cantidad) = 0;
};

class AritProg : public Progresion{
    int inc;
public:
    AritProg(long p_first, int p_inc);
    long nextValue() override ;
    long calcular(std::vector<long>p_v1, int cantidad) override;
    std::vector<long> generarProgresion( int cantidad) override ;
};
class GeoProg : public Progresion{
    int base;
public:
    GeoProg(long p_first, int p_base);
    long nextValue() override ;
    long calcular(std::vector<long>p_v1, int cantidad) override;
    std::vector<long> generarProgresion(int cantidad) override ;
};
void imprimir(Progresion* p1);
void imprimirSuma(long suma);


#endif //PROGRESIONES_POLIMORFISMO_PROGRESION_H
