// Created by felix on 4/24/2019.
#ifndef POLI1RIVAS_PROGRESSION_H
#define POLI1RIVAS_PROGRESSION_H

#include <vector>
class Progression {
protected:
    long first;
    long cur;
public:
    Progression();
    //explicit Progression(long first);
    virtual long firsValue();
    virtual long nextValue() = 0;
    //virtual void printProgression(int );
    long getCur();
    virtual long getAtribute()=0;
};
class ArithProgression : public Progression{
    long inc;
public:
    ArithProgression();
    explicit ArithProgression(long inc);
    long nextValue() override;
    long getAtribute() override;
    long getInc();
};
class GeoProgression : public Progression{
    long base;
public:
    GeoProgression();
    explicit GeoProgression(long base);
    long nextValue() override;
    long getAtribute() override;
};
class FibonacciProgression : public Progression{
    long prev;
public:
    FibonacciProgression();
    FibonacciProgression(long prev, long first);
    long nextValue() override;
    long getAtribute() override;
};

std::vector<long> get_series(Progression* p, int quantity);
long calculate_total(Progression* p, int quantity);


#endif //POLI1RIVAS_PROGRESSION_H
